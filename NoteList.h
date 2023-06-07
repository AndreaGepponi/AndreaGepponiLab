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

    void save()const;

    void addNote();

    void printAll ()const;

    void printNote(const string & NoteName)const;

    void removeNote(const string & NoteName);

    void removeAll();

    void modify(const string & NoteName);

    void deadLine(const string & NoteName);

    void noDeadLine(const string & NoteName);

    bool checkDuplicate(const string & NoteName)const;

    void sort();

    static vector<string> split(const string & s,const string & delimiter);

    string readTerminal()const;

    vector<Note> & getNoteVector() {
        return NoteVector;
    }
private:
    vector<Note> NoteVector;
};
#endif //ANDREAGEPPONILAB_NOTELIST_H
