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
    ASSERT_TRUE(Try.checkDuplicate(N));
    ASSERT_FALSE(Try.checkDuplicate(N1));
}

TEST(NoteList,TestFind){
    NoteList Try;
    string N1="Dummy";
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    ASSERT_TRUE(Try.findNote(N));
    ASSERT_FALSE(Try.findNote(N1));
}

TEST(NoteList,TestPrint){
    NoteList Try;
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    ASSERT_EQ(0,Try.printNote(N));
    ASSERT_EQ(1,Try.printNote(D));
}

TEST(NoteList,TestModify){
    NoteList Try;
    string N="DummyName",D="DummyDescription",P="No";
    string NewDescription="Dummy";
    Try.addNote(N,D,P);
    ASSERT_EQ(0,Try.modify(N,NewDescription));
}

TEST(NoteList,TestSort){
    NoteList Try;
    string N="Name",D="Description",P="No";
    string NewName="DummyName",NewDescription="NewDescription";
    Try.addNote(N,D,P);
    Try.addNote(NewName,NewDescription,P);
    Try.sort();
    ASSERT_EQ(Try.getNoteVector()[0].getName(),"DummyName");
    ASSERT_EQ(Try.getNoteVector()[1].getName(),"Name");
}

TEST(NoteList,TestSlpit){
    string Input="Name/Description";
    string separator="/";
    vector<string> Output=NoteList::split(Input,separator);
    ASSERT_EQ(Output[0],"Name");
    ASSERT_EQ(Output[1],"Description");
}

TEST(NoteList,TestImportant){
    NoteList Try;
    string N="Name",D="Description",P="yes";
    Try.addNote(N,D,P);
    ASSERT_EQ(1,Try.printImportant());
}

TEST(NoteList,TestExpired){
    NoteList Try;
    string N="Name",D="Description",P="yes";
    Try.addNote(N,D,P);
    int y=1900,m=10,d=20;
    Date Giorno;
    Giorno.addDate(y,m,d);
    Try.deadLine(N,Giorno);
    ASSERT_EQ(1,Try.printExpired());
}

TEST(NoteList,TestPrintAll){
    NoteList Try;
    ASSERT_EQ(0,Try.printAll());
    string N="Name",D="Description",P="yes";
    Try.addNote(N,D,P);
    ASSERT_EQ(1,Try.printAll());
}