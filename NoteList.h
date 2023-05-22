//
// Created by geppo on 22/05/2023.
//

#ifndef ANDREAGEPPONILAB_NOTELIST_H
#define ANDREAGEPPONILAB_NOTELIST_H
#include"Note.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class NoteList{
public:
    explicit NoteList(){
        init();
    }

    void init();

    void save();

    void addNote();

    void printAll();

    vector<string> split(const string& s,const string& delimiter);

    string readTerminal();

    vector<Note> &getNoteVector(){
        return NoteVector;
    }
private:
vector<Note> NoteVector;
};
#endif //ANDREAGEPPONILAB_NOTELIST_H
