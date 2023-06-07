//
// Created by geppo on 22/05/2023.
//
#include "NoteList.h"
#include <windows.h>
#include <algorithm>

NoteList::NoteList(){
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
    }

void NoteList::save()const{
    ofstream fText("Testo.txt");
    for(auto & index : NoteVector){
        if(index.getDate() != nullptr){
            fText << index.getName() <<"/";
            fText << index.getDescription() <<"/";
            fText << index.getPriority() <<"/";
            fText << index.getDate()->getDay() <<"/";
            fText << index.getDate()->getMonth() <<"/";
            fText << index.getDate()->getYear() <<";"<<endl;
        }
        else{
            fText << index.getName() <<"/";
            fText << index.getDescription() <<"/";
            fText << index.getPriority() <<";"<<endl;
        }
    }
    fText.close();
}

int NoteList::addNote(const string & NameString, const string & DesString, const string & Important, const string & needDate, int day, int month, int year){

    string Value;
    if(Important=="yes"||Important=="Yes"||Important=="y"){
       Value="High";
    }
    else{
        Value="Low";
    }
    Note Activity(NameString,DesString,Value);

    NoteVector.emplace_back(Activity);
    sort();

    if(needDate=="yes" || needDate=="Yes" || needDate=="y"){
        Date* Giorno=new Date;
        Giorno->addDate(year,month,day);
        if(!Giorno->legalDate(year,month,day))
            return 1;
        deadLine(NameString,Giorno);
        return 2;
    }
    return 0;
}

void NoteList::printAll()const{
    if(NoteVector.empty()){
        cout<<"The list is empty."<<endl;
    }
    else{
        cout<<"Note number:"<<NoteVector.size()<<endl;
        int counter=1;
        HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
        cout<<"[#]Name|Status|Priority"<<endl;cout<<endl;
        for(auto & index : NoteVector){
            const string& Name=index.getName();
            const string& Value=index.getPriority();
            cout<<"[" <<counter <<"]"<< Name << "|";
            if(index.getDate()!=nullptr){
                int today=index.getDate()->CheckDate();
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

void NoteList::printImportant() const {
    int count=0;
    for(auto & index:NoteVector){
        if(index.getPriority()=="High") {
            index.Print();
            cout<<"==="<<endl;
            count++;
        }
    }
    cout<<"There are "<<count<<" important note in the list."<<endl;
}

void NoteList::printExpired() const {
    int count=0;
    for(auto & index:NoteVector){
        if(index.getDate()->CheckDate()==2) {
            index.Print();
            cout<<"==="<<endl;
            count++;
        }
    }
    cout<<"There are "<<count<<" expired note in the list."<<endl;
}

int NoteList::printNote(const string & NoteName)const{
    if(findNote(NoteName)) {
        for (auto index = NoteVector.begin(); index != NoteVector.end() + 1; index++) {
            if (index->getName() == NoteName) {
                index->Print();
                return 0;
            }
        }
    }
    else
        return 1;
}

int NoteList::removeNote(const string & NoteName) {
    if(findNote(NoteName)) {
        for (auto index = NoteVector.begin(); index != NoteVector.end() + 1; index++) {
            if (index->getName() == NoteName) {
                NoteVector.erase(index);
            }
        }
        cout << "List updated." << endl;
        return 0;
    }
    else
        return 1;
}

void NoteList::removeAll() {
    NoteVector.clear();
    cout<<"The list is now empty."<<endl;
}

int NoteList::modify(const string & NoteName, const string & NoteDescription){
    if(findNote(NoteName)) {
        for (auto index = NoteVector.begin(); index != NoteVector.end() + 1; index++) {
            if (index->getName() == NoteName) {
                index->setDescription(NoteDescription);
                cout << "The note has been modified." << endl;
                return 0;
            }
        }
    }
    else
        return 1;
}

bool NoteList::deadLine(const string & NoteName, Date*Giorno) {
    if (findNote(NoteName)) {
    vector<Note>::iterator index;
    for (index = NoteVector.begin(); index != NoteVector.end(); index++) {
        if (NoteName == index->getName()) {
            index->setDate(Giorno);
            cout << "Deadline added." << endl;
            return true;
        }
    }
    }
    else
     return false;
}

int NoteList::noDeadLine(const string & NoteName) {
    if(findNote(NoteName)) {
        for (auto &index: NoteVector) {
            if (index.getName() == NoteName) {
                index.eraseDate();
                cout<<"Deadline removed."<<endl;
                return 0;
            }
        }
    }
    else
        return 1;
}

bool NoteList::checkDuplicate(const string & NoteName) const{
    for(auto & index : NoteVector){
        if(index.getName()==NoteName)
            return true;
    }
    return false;
}

void NoteList::sort(){
    ::sort(NoteVector.begin(), NoteVector.end(), [](const Note & NoteA, const Note & NoteB){
        return NoteA.getName() < NoteB.getName();
    });
}

vector <string> NoteList::split(const string & s, const string & delimiter){
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

bool NoteList::findNote(const std::string &NoteName) const{
    for(auto index=NoteVector.begin();index!=NoteVector.end()+1;index++){
        if(index->getName()==NoteName){
            return true;
        }
        if(index==NoteVector.end()){
            return false;
        }
    }
}