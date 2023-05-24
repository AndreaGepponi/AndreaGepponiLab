//
// Created by geppo on 24/05/2023.
//
#include"gtest/gtest.h"
#include"../Date.h"

TEST(Date,TestToday){
    Date Oggi;
    time_t my_time=time(nullptr);
    struct tm* local=localtime(&my_time);

    Oggi.setDay(local->tm_mday);
    Oggi.setMonth(local->tm_mon+1);
    Oggi.setYear(local->tm_year+1900);

    int x=Oggi.CheckDate(Oggi);
    ASSERT_EQ(0,x);
}