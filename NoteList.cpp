//
// Created by geppo on 22/05/2023.
//
#include "NoteList.h"
#include <windows.h>
#include <algorithm>

void NoteList::init(){
    ifstream fText("Testo.txt",ifstream::in);
    vector<string> Trasfer;
    int Year,Month,Day;
    string aux,Name,Description,Priority,delimiter="/";

    while (getline(fText,aux)){
        stringstream stream(aux);
        while(getline(stream,aux,';')){
            Trasfer=split(aux,delimiter);
            if(Trasfer.size()<5){
                Name=Trasfer[0];
                Description=Trasfer[1];
                Priority=Trasfer[2];
                Note Activity(Name,Description,Priority);

                NoteVector.emplace_back(Activity);
            }
            else{
                Name=Trasfer[0];
                Description=Trasfer[1];
                Priority=Trasfer[2];
                Note Activity(Name,Description,Priority);

                Day=stoi(Trasfer[3]);
                Month=stoi(Trasfer[4]);
                Year=stoi(Trasfer[5]);

                Date* Giorno=new Date;
                Giorno->setDay(Day);
                Giorno->setMonth(Month);
                Giorno->setYear(Year);
                Activity.setDate(Giorno);

                NoteVector.emplace_back(Activity);
            }
        }
    }
}  //da file txt a vector

void NoteList::save(){
    ofstream fText("Testo.txt");
    vector<Note>::iterator index;
    for(index=NoteVector.begin();index!=NoteVector.end();index++){
        if(index->getDate() != nullptr){
            fText << index->getName() <<"/";
            fText << index->getDescription() <<"/";
            fText << index->getPriority() <<"/";
            fText << index->getDate()->getDay() <<"/";
            fText << index->getDate()->getMonth() <<"/";
            fText << index->getDate()->getYear() <<";"<<endl;
        }
        else{
            fText << index->getName() <<"/";
            fText << index->getDescription() <<"/";
            fText << index->getPriority() <<";"<<endl;
        }
    }
    fText.close();
} //da vect a file txt

void NoteList::addNote(){
    string Value,Des,Nam;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"Insert name:";
    Nam=readTerminal();

    bool control= checkDuplicate(Nam);
    if(control){
        SetConsoleTextAttribute(hConsole,4);
        cout<<"//Name already used.Use a new name.//"<<endl;
        SetConsoleTextAttribute(hConsole,7);
        addNote();
        return;
    }

    cout<<"Insert description:";
    Des=readTerminal();

    cout<<"Insert priority(High/Low):";
    cin>>Value;
    if(Value!="High"&& Value!="Low"){
        SetConsoleTextAttribute(hConsole,4);
        cout<<"//Unknown priority.Need to insert from the beginning.//"<<endl;
        SetConsoleTextAttribute(hConsole,7);
        addNote();
        return;
    }
    Note Activity(Nam,Des,Value);
    cout<<"Add expiration date?";
    string answer;
    cin>>answer;
    if(answer=="yes" || answer=="Yes" || answer=="y"){
        Date* Giorno=new Date;
        Giorno->addDate();
        Activity.setDate(Giorno);
        cout<<"Deadline added."<<endl;
        if(int check=Giorno->CheckDate(*Giorno)==2){
            SetConsoleTextAttribute(hConsole,4);
            cout<<"//WARNING:Deadline already expired//"<<endl;
            SetConsoleTextAttribute(hConsole,7);
        }
    }
    NoteVector.emplace_back(Activity);
    sort();
    cout<<"List updated."<<endl;
}

void NoteList::printAll() {
    if(NoteVector.empty()){
        cout<<"The list is empty."<<endl;
    }
    else{
        vector<Note>::iterator index;
        int counter=1;
        HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
        cout<<"[#]Name|Status|Priority"<<endl;cout<<endl;
        for(index=NoteVector.begin();index!=NoteVector.end();index++){
            string Name=index->getName();
            string Value=index->getPriority();
            cout<<"[" <<counter <<"]"<< Name << "|";
            if(index->getDate()!=nullptr){
                int today=index->getDate()->CheckDate(*index->getDate());
                if(today==0){
                    SetConsoleTextAttribute(hConsole,6);
                    cout<<"EXPIRE TODAY";
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"|";
                }
                else if(today==2){
                    SetConsoleTextAttribute(hConsole,5);
                    cout<<"EXPIRED";
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"|";
                }
                else{
                    SetConsoleTextAttribute(hConsole,3);
                    cout<<"NOT EXPIRED";
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"|";
                }
            }
            else{
                SetConsoleTextAttribute(hConsole,8);
                cout<<"No expiration";
                SetConsoleTextAttribute(hConsole,7);
                cout<<"|";
            }
            if(Value=="Low"){
                SetConsoleTextAttribute(hConsole,1);
                cout<< Value <<endl;
                SetConsoleTextAttribute(hConsole,7);
            }
            else{
                SetConsoleTextAttribute(hConsole,4);
                cout<< Value <<endl;
                SetConsoleTextAttribute(hConsole,7);
            }
            counter++;
        }
    }
}

void NoteList::printNote(const string& NoteName){
    vector<Note>::iterator index;
    for(index=NoteVector.begin();index!=NoteVector.end();index++){
        if(index->getName()==NoteName){
            index->Print();
            break;
        }
    }
    if(index==NoteVector.end()){
        cout<<"Note not found."<<endl;
    }
}

void NoteList::removeNote(const string &NoteName) {
    for(vector<Note>::iterator index=NoteVector.begin(); index != NoteVector.end() + 1; index++){
        if(index->getName() == NoteName){
            NoteVector.erase(index);
        }
    }
    cout<<"List updated."<<endl;
}

void NoteList::removeAll() {
    NoteVector.clear();
    cout<<"The list is now empty."<<endl;
}

void NoteList::modify(const string& NoteName){
    vector<Note>::iterator index;
    for(index=NoteVector.begin();index!=NoteVector.end();index++){
        if(index->getName()==NoteName){
            cout<<"Insert new description:";
            string des=readTerminal();
            index->setDescription(des);
            cout<<"The note has been modified."<<endl;
            break;
        }
    }
    if(index==NoteVector.end()){
        cout<<"Note not found."<<endl;
    }
}

bool NoteList::checkDuplicate(const std::string &NoteName) {
    vector<Note>::iterator index;
    for(index=NoteVector.begin();index!=NoteVector.end();index++){
        if(index->getName()==NoteName)
            return true;
    }
    return false;
}

void NoteList::sort(){
    ::sort(NoteVector.begin(), NoteVector.end(), [](const Note & NoteA, const Note & NoteB){
        return NoteA.getName() < NoteB.getName();
    });
}

vector <string> NoteList::split(const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

string NoteList::readTerminal(){
    vector<string> Trasfer;
    string input,support,output,del=" ";

    cin>>input;cout<<endl;
    support=input;
    getline(cin,input);
    support+=input;
    Trasfer=split(support,del);
    for(vector<string>::iterator index=Trasfer.begin();index!=Trasfer.end();index++){
        output+=*index;
        output.push_back(' ');
    }
    output.pop_back();
    return output;
}