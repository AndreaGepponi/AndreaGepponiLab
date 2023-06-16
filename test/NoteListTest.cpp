//
// Created by geppo on 24/05/2023.
//
#include "gtest/gtest.h"

#include "../NoteList.h"

TEST(NoteList,TestEmpty){
    NoteList Try;
    Try.removeAll();
    ASSERT_EQ(0,Try.getNoteVector().size());
}


TEST(NoteList,TestRemove){
    NoteList Try;
    string dummyName="sampleName",dummyDescription="sampleDescription",dummyPriority="Low";
    Note Activity(dummyName,dummyDescription,dummyPriority);
    Try.getNoteVector().emplace_back(Activity);
    int size=Try.getNoteVector().size();
    Try.removeNote(dummyName);
    ASSERT_EQ(size-1,Try.getNoteVector().size());
}

TEST(NoteList,TestAddNote){
    NoteList Try;
    string N="DummyName",D="DummyDescription",P="No";
    int size1=Try.getNoteVector().size();
    Try.addNote(N,D,P);
    int size2=Try.getNoteVector().size();
    ASSERT_EQ(size1+1,size2);
}

TEST(NoteList,TestExpire){
    NoteList Try;

    string N="DummyName",D="DummyDescription",P="No";

    Date expireDay;
    expireDay.setYear(2000);
    expireDay.setMonth(11);
    expireDay.setDay(20);

    Try.addNote(N,D,P);
    Try.deadLine(N,expireDay);

    ASSERT_NE(nullptr,Try.getNoteVector()[0].getDate());
}

TEST(NoteList,TestNoExpire){
    NoteList Try;

    string N="DummyName",D="DummyDescription",P="No";

    Date expireDay;
    expireDay.setYear(2000);
    expireDay.setMonth(11);
    expireDay.setDay(20);

    Try.addNote(N,D,P);
    Try.deadLine(N,expireDay);
    Try.noDeadLine(N);
    ASSERT_EQ(nullptr,Try.getNoteVector()[0].getDate());
}

TEST(NoteList,TestDuplicate){
    NoteList Try;
    string N1="Dummy";
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    bool x=Try.checkDuplicate(N);
    bool y=Try.checkDuplicate(N1);
    ASSERT_EQ(true,x);
    ASSERT_EQ(false,y);
}

TEST(NoteList,TestFind){
    NoteList Try;
    string N1="Dummy";
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    bool x=Try.findNote(N);
    bool y=Try.findNote(N1);
    ASSERT_EQ(true,x);
    ASSERT_EQ(false,y);
}