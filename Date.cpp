//
// Created by geppo on 19/05/2023.
//
#include "Date.h"
#include <iostream>
#include <windows.h>
using namespace std;

void Date::show() {
    cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear();
}

int Date::CheckDate(const Date& Data) {
    time_t my_time=time(nullptr);
    struct tm* local=localtime(&my_time);

    int day=local->tm_mday;
    int month=local->tm_mon+1;
    int year=local->tm_year+1900;

    if(Data.getYear()==year && Data.getMonth()==month && Data.getDay()==day){
        return 0;
    }

    if(Data.getYear() > year){
        return 1;
    }

    if(Data.getYear() < year){
        return 2;
    }

    else{
        if(Data.getMonth() > month){
            return 1;
        }
        if(Data.getMonth() < month){
            return 2;
        }
        else{
            if(Data.getDay() >= day){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
}