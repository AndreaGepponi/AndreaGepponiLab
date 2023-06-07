#include <iostream>
#include "NoteList.h"
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

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

    if(TerminalInput[0]=="expire"){
        string InputString=compact(TerminalInput);
        ToDoList.deadLine(InputString);
        separate();
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="noexpire"){
        string InputString=compact(TerminalInput);
        ToDoList.noDeadLine(InputString);
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="add"){
        ToDoList.addNote();
        separate();
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="remove"){
        string InputString=compact(TerminalInput);
        ToDoList.removeNote(InputString);
        separate();
        ToDoList.printAll();
        separate();
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="print"){
        string InputString=compact(TerminalInput);
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
        Interaction(ToDoList);
    }

    else if(TerminalInput[0]=="modify"){
        string InputString= compact(TerminalInput);
        ToDoList.modify(InputString);
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
