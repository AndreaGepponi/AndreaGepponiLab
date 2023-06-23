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
    ASSERT_TRUE(day.setDay(30));
    ASSERT_FALSE(day.setDay(31));
}

TEST(Date,TestMonth){
    Date month;
    month.setYear(2003);
    month.setDay(29);
    ASSERT_TRUE(month.setMonth(3));
    ASSERT_FALSE(month.setMonth(2));
}

TEST(Date,TestYear){
    Date year;
    year.setDay(29);
    year.setMonth(2);
    ASSERT_TRUE(year.setYear(2000));
    ASSERT_FALSE(year.setYear(2001));
}

TEST(Date,TestDate){
    Date Giorno;
    ASSERT_TRUE(Giorno.addDate(1994,9,11));
}