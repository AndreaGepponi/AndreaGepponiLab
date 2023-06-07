//
// Created by geppo on 19/05/2023.
//
#include "Date.h"
#include <iostream>
#include <sstream>
using namespace std;

void Date::show() const {
    stringstream output;
    output<<getDay()<<"/"<<getMonth()<<"/"<<getYear();
    string out;
    output>>out;
    cout<<out<<endl;
}

int Date::CheckDate() {
    time_t my_time=time(nullptr);
    struct tm* local=localtime(&my_time);

    int Dyear=getYear(),Dmonth=getMonth(),Dday=getDay();
    int day=local->tm_mday;
    int month=local->tm_mon+1;
    int year=local->tm_year+1900;

    if(Dyear==year && Dmonth==month && Dday==day){
        return 0;
    }

    if(Dyear > year){
        return 1;
    }

    if(Dyear < year){
        return 2;
    }

    else{
        if(Dmonth > month){
            return 1;
        }
        if(Dmonth < month){
            return 2;
        }
        else{
            if(Dday >= day){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
}

bool Date::addDate(int year, int month, int day){
    if(legalDate(year,month,day)){
        setYear(year);
        setMonth(month);
        setDay(day);
        return true;
    }
    else
        return false;
}

int Date::setYear(int year){

    int m=getMonth();
    int d=getDay();
    if(legalDate(year,m,d)){
        Year=year;
        return 0;
    }
    else
        return 1;
}

int Date::setMonth(int month){

    int y=getYear();
    int d=getDay();
    if(legalDate(y,month,d)){
        Month=month;
        return 0;
    }
    else
        return 1;
}

int Date::setDay(int day){

        int y=getYear();
        int m=getMonth();
        if(legalDate(y,m,day)){
            Day=day;
            return 0;
        }
        else
            return 1;
}

bool Date::legalDate(int year,int month,int day) {
    bool bisestile=false;
    if((year%4==0 && year%100!=0) || year%400==0)
        bisestile=true;

    if(0<month && month<13){
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            if(day<1 || day>31){
                return false;
            }
        }
        else if(month==4||month==6||month==9||month==11){
            if(day<1 || day>30){
                return false;
            }
        }
        else if(bisestile){
            if(day<1 || day>29){
                return false;
            }
        }
        else{
            if(day<1 || day>28){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}