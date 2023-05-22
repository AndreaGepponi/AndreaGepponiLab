#include <iostream>
#include "NoteList.h"
using namespace std;

int main() {
    NoteList ToDoList;
    ToDoList.addNote();
    ToDoList.printAll();
    ToDoList.save();
    return 0;
}
