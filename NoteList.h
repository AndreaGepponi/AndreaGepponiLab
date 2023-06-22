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
    explicit NoteList(const string& FileName);

    void save(const string& FileName)const;

    void addNote(const string & NameString, const string & DesString, const string & Important);

    int printAll ()const;

    int printImportant()const;

    int printExpired()const;

    int printNote(const string & NoteName)const;

    int removeNote(const string & NoteName);

    void removeAll();

    int modify(const string & NoteName, const string & NoteDescription);

    bool deadLine(const string & NoteName, Date &Giorno);

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
