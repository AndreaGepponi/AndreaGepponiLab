//
// Created by geppo on 19/05/2023.
//

#ifndef ANDREAGEPPONILAB_NOTE_H
#define ANDREAGEPPONILAB_NOTE_H
#include <string>
using namespace std;
class Note{
public:
    Note(string N,string D,string P):Name(move(N)),Description(move(D)),Priority(move(P)){};

    const string &getName() const {
        return Name;
    }

    void setName(const string &name) {
        Name = name;
    }

    const string &getDescription() const {
        return Description;
    }

    void setDescription(const string &description) {
        Description = description;
    }

    const string &getPriority() const {
        return Priority;
    }

    void setPriority(const string &priority) {
        Priority = priority;
    }

private:
string Name,Description,Priority;
};
#endif //ANDREAGEPPONILAB_NOTE_H
