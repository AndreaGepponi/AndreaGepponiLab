#include <iostream>
#include "NoteList.h"
#include <vector>
#include <string>
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

string compact(vector<string> InputCommand){
    string output;
    for(int index=1;index<InputCommand.size();index++){
        output+=InputCommand[index];
        output.push_back(' ');
    }
    output.pop_back();
    return output;
}

int main() {
    NoteList ToDoList;
    ToDoList.printAll();
    cout<<"---------------"<<endl;
    vector<string>TerminalInput=splitTerminal();
    string InputString=compact(TerminalInput);
    ToDoList.deadLine(InputString);
    cout<<"---------------"<<endl;
    ToDoList.printAll();
    cout<<"---------------"<<endl;
    ToDoList.noDeadLine(InputString);
    cout<<"---------------"<<endl;
    ToDoList.printAll();
    ToDoList.save();
    return 0;
}
