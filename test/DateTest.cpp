//
// Created by geppo on 24/05/2023.
//
#include"gtest/gtest.h"
#include"../Date.h"

TEST(Date,CheckDate){
    Date Today,Past,Future;
    time_t my_time=time(nullptr);
    struct tm* local=localtime(&my_time);

    Today.setDay(local->tm_mday);
    Today.setMonth(local->tm_mon + 1);
    Today.setYear(local->tm_year + 1900);

    Past.setDay(local->tm_mday);
    Past.setMonth(local->tm_mon + 1);
    Past.setYear(local->tm_year + 1899);

    Future.setDay(local->tm_mday);
    Future.setMonth(local->tm_mon+1);
    Future.setYear(local->tm_year + 1901);

    int x=Today.CheckDate();
    int y=Future.CheckDate();
    int z=Past.CheckDate();

    ASSERT_EQ(0,x);
    ASSERT_EQ(1,y);
    ASSERT_EQ(2,z);
}

TEST(Date,TestDay){
    Date day;
    day.setYear(1997);
    day.setMonth(4);
    int x=day.setDay(30);
    int y=day.setDay(31);
    ASSERT_EQ(0,x);
    ASSERT_NE(0,y);
}

TEST(Date,TestMonth){
    Date month;
    month.setYear(2003);
    month.setDay(29);
    int x=month.setMonth(3);
    int y=month.setMonth(2);
    ASSERT_EQ(0,x);
    ASSERT_NE(0,y);
}

TEST(Date,TestYear){
    Date year;
    year.setDay(29);
    year.setMonth(2);
    int x=year.setYear(2000);
    int y=year.setYear(2001);
    ASSERT_EQ(0,x);
    ASSERT_NE(0,y);
}

TEST(Date,TestDate){
    Date Giorno;
    int y=1994,m=9,d=11;
    ASSERT_TRUE(Giorno.addDate(y,m,d));
}

TEST(Date,TestLegal){
    Date Giorno;
    int y=1994,m=9,d=11;
    Giorno.addDate(y,m,d);
    ASSERT_TRUE(Giorno.legalDate());
}