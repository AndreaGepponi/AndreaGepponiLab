#include "gtest/gtest.h"

#include "../NoteList.h"

TEST(NoteList,TestConstructor){
    int x=1,y=1;
    NoteList Test("Constructor.txt");
    if(Test.getNote("Activity").getName()=="Activity" && Test.getNote("Activity").getDescription() == "Des" &&
       Test.getNote("Activity").getPriority() == "Low")
        x=0;
    if(Test.getNote("Prova").getName() == "Prova" && Test.getNote("Prova").getDescription() == "Des" &&
       Test.getNote("Prova").getPriority() == "High")
        y=0;
    ASSERT_EQ(x,0);
    ASSERT_EQ(y,0);
    ASSERT_EQ(Test.getNoteVector().size(), 2);
    ASSERT_NE(Test.getNoteVector()[0].getDate(), nullptr);
    ASSERT_EQ(Test.getNoteVector()[1].getDate(), nullptr);
}

TEST(NoteList,TestSave){
    NoteList Test("Save.txt");
    Test.removeAll();
    string N="DummyName",D="DummyDescription",P="No";
    Test.addNote(N, D, P);
    Test.save("Save.txt");
    NoteList Testcheck("Save.txt");
    ASSERT_EQ(Testcheck.getNoteVector().size(),1);
    ASSERT_EQ(Testcheck.getNote("DummyName").getName(),"DummyName");
    ASSERT_EQ(Testcheck.getNote("DummyName").getDescription(),"DummyDescription");
    ASSERT_EQ(Testcheck.getNote("DummyName").getPriority(),"Low");
}

TEST(NoteList,TestEmpty){
    NoteList Test("Test.txt");
    Test.removeAll();
    ASSERT_EQ(0, Test.getNoteVector().size());
}

TEST(NoteList,TestRemove){
    NoteList Test("Test.txt");
    string dummyName="sampleName",dummyDescription="sampleDescription",dummyPriority="No";

    Test.addNote(dummyName,dummyDescription,dummyPriority);
    int size=Test.getNoteVector().size();
    ASSERT_TRUE(Test.removeNote(dummyName));
    ASSERT_EQ(size-1, Test.getNoteVector().size());
    Test.removeAll();
}

TEST(NoteList,TestAddNote){
    NoteList Test("Test.txt");
    string N="DummyName",D="DummyDescription",P="No";
    int size=Test.getNoteVector().size();
    Test.addNote(N, D, P);
    ASSERT_EQ(size+1,Test.getNoteVector().size());
    Test.removeAll();
}

TEST(NoteList,TestExpire){
    NoteList Test("Test.txt");

    string N="DummyName",D="DummyDescription",P="No";

    Date expireDay;
    expireDay.addDate(2000,11,20);

    Test.addNote(N, D, P);
    Test.deadLine(N, expireDay);

    ASSERT_NE(nullptr, Test.getNote("DummyName").getDate());
    Test.removeAll();
}

TEST(NoteList,TestNoExpire){
    NoteList Test("Test.txt");

    string N="DummyName",D="DummyDescription",P="No";

    Date expireDay;
    expireDay.addDate(2000,11,20);

    Test.addNote(N, D, P);
    Test.deadLine(N, expireDay);
    ASSERT_TRUE(Test.noDeadLine(N));
    ASSERT_EQ(nullptr, Test.getNote("DummyName").getDate());
    Test.removeAll();
}

TEST(NoteList,TestDuplicate){
    NoteList Test("Test.txt");
    string N1="Dummy";
    string N="DummyName",D="DummyDescription",P="No";
    Test.addNote(N, D, P);
    ASSERT_TRUE(Test.checkDuplicate(N));
    ASSERT_FALSE(Test.checkDuplicate(N1));
    Test.removeAll();
}

TEST(NoteList,TestFind){
    NoteList Test("Test.txt");
    string N1="Dummy";
    string N="DummyName",D="DummyDescription",P="No";
    Test.addNote(N, D, P);
    ASSERT_TRUE(Test.findNote(N));
    ASSERT_FALSE(Test.findNote(N1));
    Test.removeAll();
}

TEST(NoteList,TestPrint){
    NoteList Test("Test.txt");
    string N="DummyName",D="DummyDescription",P="No";
    Test.addNote(N, D, P);
    ASSERT_TRUE(Test.printNote(N));
    ASSERT_FALSE(Test.printNote(D));
    Test.removeAll();
}

TEST(NoteList,TestModify){
    NoteList Test("Test.txt");
    string N="DummyName",D="DummyDescription",P="No";
    string NewDescription="Dummy";
    Test.addNote(N, D, P);
    ASSERT_TRUE(Test.modify(N, NewDescription));
    Test.removeAll();
}

TEST(NoteList,TestSort){
    NoteList Test("Test.txt");
    string N="Name",D="Description",P="No";
    string NewName="DummyName",NewDescription="NewDescription";
    Test.addNote(N, D, P);
    Test.addNote(NewName, NewDescription, P);
    Test.sort();
    ASSERT_EQ(Test.getNote("DummyName").getName(), "DummyName");
    ASSERT_EQ(Test.getNote("Name").getName(), "Name");
    Test.removeAll();
}

TEST(NoteList,TestSlpit){
    string Input="Name/Description";
    string separator="/";
    vector<string> Output=NoteList::split(Input,separator);
    ASSERT_EQ(Output[0],"Name");
    ASSERT_EQ(Output[1],"Description");
}

TEST(NoteList,TestImportant){
    NoteList Test("Test.txt");
    string N="Name",D="Description",P="yes";
    Test.addNote(N, D, P);
    ASSERT_EQ(1, Test.printImportant());
    Test.removeAll();
}

TEST(NoteList,TestExpired){
    NoteList Test("Test.txt");
    string N="Name",D="Description",P="yes";
    Test.addNote(N, D, P);
    Date Giorno;
    Giorno.addDate(1900,10,20);
    Test.deadLine(N, Giorno);
    ASSERT_EQ(1, Test.printExpired());
    Test.removeAll();
}

TEST(NoteList,TestPrintAll){
    NoteList Test("Test.txt");
    ASSERT_EQ(0, Test.printAll());
    string N="Name",D="Description",P="yes";
    Test.addNote(N, D, P);
    ASSERT_EQ(1, Test.printAll());
    Test.removeAll();
}

TEST(NoteList,TestGetNote){
    NoteList Test("Test.txt");
    string N="Name",D="Description",P="yes";
    Test.addNote(N, D, P);
    ASSERT_EQ(Test.getNote("Name").getName(),"Name");
    ASSERT_EQ(Test.getNote("Name").getDescription(),"Description");
    ASSERT_EQ(Test.getNote("Name").getPriority(),"High");
    Test.removeAll();
}