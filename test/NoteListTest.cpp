//
// Created by geppo on 24/05/2023.
//
#include "gtest/gtest.h"

#include "../NoteList.h"

TEST(NoteList,TestConstructor){
    NoteList Try("Constructor.txt");
    ASSERT_EQ(Try.getNoteVector().size(),2);
    ASSERT_NE(Try.getNoteVector()[0].getDate(),nullptr);
    ASSERT_EQ(Try.getNoteVector()[1].getDate(),nullptr);
}

TEST(NoteList,TestSave){
    NoteList Try("Save.txt");
    Try.removeAll();
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    Try.save("Save.txt");
    NoteList Trycheck("Save.txt");
    ASSERT_EQ(Trycheck.getNoteVector().size(),1);
    ASSERT_EQ(Trycheck.getNoteVector()[0].getName(),"DummyName");
    ASSERT_EQ(Trycheck.getNoteVector()[0].getDescription(),"DummyDescription");
    ASSERT_EQ(Trycheck.getNoteVector()[0].getPriority(),"Low");
}

TEST(NoteList,TestEmpty){
    NoteList Try("Test.txt");
    Try.removeAll();
    ASSERT_EQ(0,Try.getNoteVector().size());
}

TEST(NoteList,TestRemove){
    NoteList Try("Test.txt");
    string dummyName="sampleName",dummyDescription="sampleDescription",dummyPriority="Low";
    Note Activity(dummyName,dummyDescription,dummyPriority);
    Try.getNoteVector().emplace_back(Activity);
    int size=Try.getNoteVector().size();
    Try.removeNote(dummyName);
    ASSERT_EQ(size-1,Try.getNoteVector().size());
    Try.removeAll();
}

TEST(NoteList,TestAddNote){
    NoteList Try("Test.txt");
    string N="DummyName",D="DummyDescription",P="No";
    int size1=Try.getNoteVector().size();
    Try.addNote(N,D,P);
    int size2=Try.getNoteVector().size();
    ASSERT_EQ(size1+1,size2);
    Try.removeAll();
}

TEST(NoteList,TestExpire){
    NoteList Try("Test.txt");

    string N="DummyName",D="DummyDescription",P="No";

    Date expireDay;
    expireDay.setYear(2000);
    expireDay.setMonth(11);
    expireDay.setDay(20);

    Try.addNote(N,D,P);
    Try.deadLine(N,expireDay);

    ASSERT_NE(nullptr,Try.getNoteVector()[0].getDate());
    Try.removeAll();
}

TEST(NoteList,TestNoExpire){
    NoteList Try("Test.txt");

    string N="DummyName",D="DummyDescription",P="No";

    Date expireDay;
    expireDay.setYear(2000);
    expireDay.setMonth(11);
    expireDay.setDay(20);

    Try.addNote(N,D,P);
    Try.deadLine(N,expireDay);
    Try.noDeadLine(N);
    ASSERT_EQ(nullptr,Try.getNoteVector()[0].getDate());
    Try.removeAll();
}

TEST(NoteList,TestDuplicate){
    NoteList Try("Test.txt");
    string N1="Dummy";
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    ASSERT_TRUE(Try.checkDuplicate(N));
    ASSERT_FALSE(Try.checkDuplicate(N1));
    Try.removeAll();
}

TEST(NoteList,TestFind){
    NoteList Try("Test.txt");
    string N1="Dummy";
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    ASSERT_TRUE(Try.findNote(N));
    ASSERT_FALSE(Try.findNote(N1));
    Try.removeAll();
}

TEST(NoteList,TestPrint){
    NoteList Try("Test.txt");
    string N="DummyName",D="DummyDescription",P="No";
    Try.addNote(N,D,P);
    ASSERT_EQ(0,Try.printNote(N));
    ASSERT_EQ(1,Try.printNote(D));
    Try.removeAll();
}

TEST(NoteList,TestModify){
    NoteList Try("Test.txt");
    string N="DummyName",D="DummyDescription",P="No";
    string NewDescription="Dummy";
    Try.addNote(N,D,P);
    ASSERT_EQ(0,Try.modify(N,NewDescription));
    Try.removeAll();
}

TEST(NoteList,TestSort){
    NoteList Try("Test.txt");
    string N="Name",D="Description",P="No";
    string NewName="DummyName",NewDescription="NewDescription";
    Try.addNote(N,D,P);
    Try.addNote(NewName,NewDescription,P);
    Try.sort();
    ASSERT_EQ(Try.getNoteVector()[0].getName(),"DummyName");
    ASSERT_EQ(Try.getNoteVector()[1].getName(),"Name");
    Try.removeAll();
}

TEST(NoteList,TestSlpit){
    string Input="Name/Description";
    string separator="/";
    vector<string> Output=NoteList::split(Input,separator);
    ASSERT_EQ(Output[0],"Name");
    ASSERT_EQ(Output[1],"Description");
}

TEST(NoteList,TestImportant){
    NoteList Try("Test.txt");
    string N="Name",D="Description",P="yes";
    Try.addNote(N,D,P);
    ASSERT_EQ(1,Try.printImportant());
    Try.removeAll();
}

TEST(NoteList,TestExpired){
    NoteList Try("Test.txt");
    string N="Name",D="Description",P="yes";
    Try.addNote(N,D,P);
    int y=1900,m=10,d=20;
    Date Giorno;
    Giorno.addDate(y,m,d);
    Try.deadLine(N,Giorno);
    ASSERT_EQ(1,Try.printExpired());
    Try.removeAll();
}

TEST(NoteList,TestPrintAll){
    NoteList Try("Test.txt");
    ASSERT_EQ(0,Try.printAll());
    string N="Name",D="Description",P="yes";
    Try.addNote(N,D,P);
    ASSERT_EQ(1,Try.printAll());
    Try.removeAll();
}