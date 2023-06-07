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
    explicit NoteList();

    void save()const;

    int
    addNote(const string & NameString, const string & DesString, const string & Important, const string & needDate, int day, int month, int year);

    void printAll ()const;

    void printImportant()const;

    void printExpired()const;

    int printNote(const string & NoteName)const;

    int removeNote(const string & NoteName);

    void removeAll();

    int modify(const string & NoteName, const string & NoteDescription);

    bool deadLine(const string & NoteName, Date*Giorno);

    int noDeadLine(const string & NoteName);

    bool checkDuplicate(const string & NoteName)const;

    void sort();

    static vector<string> split(const string & s,const string & delimiter);

    bool findNote(const string & NoteName)const;

    vector<Note> & getNoteVector() {
        return NoteVector;
    }
private:
    vector<Note> NoteVector;
};
#endif //ANDREAGEPPONILAB_NOTELIST_H
