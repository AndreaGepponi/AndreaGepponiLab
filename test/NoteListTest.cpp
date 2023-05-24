//
// Created by geppo on 24/05/2023.
//
#include "gtest/gtest.h"

#include "../NoteList.h"

TEST(NoteList,TestExipreDate){
    NoteList Try;
    Try.removeAll();
    ASSERT_EQ(0,Try.getNoteVector().size());
}


TEST(NoteList,TestNoExpire){
    NoteList Try;
    string dummyName="sampleName",dummyDescription="sampleDescription",dummyPriority="Low";
    Note Activity(dummyName,dummyDescription,dummyPriority);
    Try.getNoteVector().emplace_back(Activity);
    int size=Try.getNoteVector().size();
    Try.removeNote(dummyName);
    ASSERT_EQ(size-1,Try.getNoteVector().size());
}