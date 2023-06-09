#ifndef ANDREAGEPPONILAB_NOTE_H
#define ANDREAGEPPONILAB_NOTE_H
#include <string>
#include <utility>
#include <iostream>
#include <windows.h>
#include "Date.h"
using namespace std;
class Note{
public:
    Note(string N,string D,string P):Name(std::move(N)),Description(std::move(D)),Priority(std::move(P)){};

    const string & getName() const {
        return Name;
    }

    const string & getDescription() const {
        return Description;
    }

    void setDescription(const string & description){
        Description = description;
    }

    const string & getPriority() const {
        return Priority;
    }

    void Print()const;

    void setDate(Date* date){
        Date=date;
    }

    Date *getDate() const{
        return Date;
    }

    void eraseDate() {
        Date=nullptr;   
    }
private:
string Name,Description,Priority;
Date* Date=nullptr;
};
#endif //ANDREAGEPPONILAB_NOTE_H
