//
// Created by geppo on 19/05/2023.
//

#include "Note.h"

void Note::Print() {
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,7);

    cout<<Name<<":"<<Description<<"|";
    if(getPriority()=="Low"){
        SetConsoleTextAttribute(hConsole,1);
        cout<<Priority<<endl;
        SetConsoleTextAttribute(hConsole,7);
    }
    else{
        SetConsoleTextAttribute(hConsole,4);
        cout<<Priority<<endl;
        SetConsoleTextAttribute(hConsole,7);
    }
    if(getDate()!=nullptr){
        cout<<"Expiration:";
        getDate()->show();
    }
}