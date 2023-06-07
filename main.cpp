#include <iostream>
#include "NoteList.h"
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

string readTerminal(){
    vector<string> Trasfer;
    string input,support,output,del=" ";

    cin>>input;cout<<endl;
    support=input;
    getline(cin,input);
    support+=input;
    Trasfer=NoteList::split(support,del);
    for(auto & index : Trasfer){
        output+=index;
        output.push_back(' ');
    }
    output.pop_back();
    return output;
}

vector<string> splitTerminal(){
    vector<string> Trasfer;
    string in,support,del="/";

    cin>>in;cout<<endl;
    support=in;
    getline(cin,in);
    support+=in;
    Trasfer=NoteList::split(support,del);
    return Trasfer;
}

string compact(const vector<string> & InputCommand){
    string output;
    for(int index=1;index<InputCommand.size();index++){
        output+=InputCommand[index];
        output.push_back(' ');
    }
    output.pop_back();
    return output;
}

void separate(){
    cout<<"=============================================================="<<endl;
}

void commands(){
    cout<<"Type add to add note."<<endl;
    cout<<"Type expire/[NoteName] to add or modify expiration date."<<endl;
    cout<<"Type noexpire/[NoteName] to remove expiration date."<<endl;
    cout<<"Type remove/[NoteName] to remove note."<<endl;
    cout<<"Type print/[NoteName] to print note."<<endl;
    cout<<"Type modify/[NoteName] to modify a note's description."<<endl;
    cout<<"Type show to show all notes names and priority."<<endl;
    cout<<"Type important to show all important notes."<<endl;
    cout<<"Type expired to show all epired notes."<<endl;
    cout<<"Type cancel to remove all notes."<<endl;
    cout<<"Type quit to quit."<<endl;
    cout<<"Type help to show command list."<<endl;
}

void Interaction(NoteList ToDoList){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,7);

    vector<string>TerminalInput;
    TerminalInput=splitTerminal();
    separate();

    if(TerminalInput[0]=="expire") {
        string InputString = compact(TerminalInput);
        if(!ToDoList.findNote(InputString)){
            cout<<"Note not existing."<<endl;
            separate();
            Interaction(ToDoList);
            return;
        }
        int year, month, day;
        cout << "Insert year:";
        cin >> year;
        cout << "Insert month:";
        cin >> month;
        cout << "Insert day:";
        cin >> day;
        Date *Giorno = new Date;
        Giorno->setDay(day);
        Giorno->setMonth(month);
        Giorno->setYear(year);
        while (Giorno->CheckDate() == 2 || !Giorno->legalDate(year,month,day)) {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "//WARNING:Deadline not valid.Insert a legal date.//" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Insert year:";
            cin >> year;
            cout << "Insert month:";
            cin >> month;
            cout << "insert day:";
            cin >> day;
            Giorno->setDay(day);
            Giorno->setMonth(month);
            Giorno->setYear(year);
           }
        ToDoList.deadLine(InputString,*Giorno);
        cout<<"Deadline added."<<endl;
        separate();
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }
    else if(TerminalInput[0]=="noexpire"){
        string InputString=compact(TerminalInput);
        if(!ToDoList.findNote(InputString)){
            cout<<"Note not existing."<<endl;
            separate();
            Interaction(ToDoList);
            return;
        }
        ToDoList.noDeadLine(InputString);
        cout<<"DeadLine removed."<<endl;
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="add"){
        string NoteName,NoteDescription,NoteImportant,NoteDate;
        int year,month,day;
        cout<<"Insert Note name:";
        NoteName=readTerminal();
        while(ToDoList.checkDuplicate(NoteName)){
            SetConsoleTextAttribute(hConsole,4);
            cout<<"//Name already used.Use a new name.//"<<endl;
            SetConsoleTextAttribute(hConsole,7);
            NoteName=readTerminal();
        }
        cout<<"Insert Note description:";
        NoteDescription=readTerminal();
        cout<<"Is important?";
        NoteImportant=readTerminal();
        ToDoList.addNote(NoteName,NoteDescription,NoteImportant);
        cout<<"Add expire date?";
        NoteDate=readTerminal();
        if(NoteDate=="yes" || NoteDate=="Yes" || NoteDate=="y"){
            cout<<"Insert year:";cin>>year;
            cout<<"Insert month:";cin>>month;
            cout<<"insert day:";cin>>day;
            Date* Giorno=new Date;
            Giorno->setDay(day);
            Giorno->setMonth(month);
            Giorno->setYear(year);
            while(Giorno->CheckDate()==2 ||!Giorno->legalDate(year,month,day)){
                SetConsoleTextAttribute(hConsole,4);
                cout<<"//WARNING:Deadline already expired.Insert a legal date.//"<<endl;
                SetConsoleTextAttribute(hConsole,7);
                cout<<"Insert year:";cin>>year;
                cout<<"Insert month:";cin>>month;
                cout<<"insert day:";cin>>day;
                Giorno->setDay(day);
                Giorno->setMonth(month);
                Giorno->setYear(year);
            }
            ToDoList.deadLine(NoteName,*Giorno);
        }
        cout<<"Note added."<<endl;
        separate();
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="remove"){
        string InputString=compact(TerminalInput);
        if(!ToDoList.findNote(InputString)){
            cout<<"Note not existing."<<endl;
            separate();
            Interaction(ToDoList);
            return;
        }
        ToDoList.removeNote(InputString);
        cout<<"Note removed."<<endl;
        separate();
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="print"){
        string InputString=compact(TerminalInput);
        if(!ToDoList.findNote(InputString)){
            cout<<"Note not existing."<<endl;
            separate();
            Interaction(ToDoList);
            return;
        }
        ToDoList.printNote(InputString);
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="show"){
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="cancel"){
        ToDoList.removeAll();
        separate();
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="modify"){
        string InputString= compact(TerminalInput);
        if(!ToDoList.findNote(InputString)){
            cout<<"Note not existing."<<endl;
            separate();
            Interaction(ToDoList);
            return;
        }
        cout<<"Insert new description:";
        string newDes=readTerminal();
        ToDoList.modify(InputString,newDes);
        cout<<"The note has been modified."<<endl;
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="help"){
        SetConsoleTextAttribute(hConsole,2);
        separate();
        commands();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="important"){
        ToDoList.printImportant();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="expired"){
        ToDoList.printExpired();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="quit"){
        ToDoList.save();
        return;
    }

    else{
        SetConsoleTextAttribute(hConsole,4);
        separate();
        cout<<"Unknown command."<<endl;
        separate();
        SetConsoleTextAttribute(hConsole,2);
        separate();
        cout<<"Type help to show command list."<<endl;
        separate();
        Interaction(ToDoList);
    }
}

int main() {
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,2);

    NoteList ToDoList;

    separate();
    commands();
    separate();

    SetConsoleTextAttribute(hConsole,7);
    ToDoList.printAll();
    separate();

    Interaction(ToDoList);
    return 0;
}
