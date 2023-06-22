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
    Date Giorno;
    Giorno.Year=year;
    Giorno.Month=month;
    Giorno.Day=day;
    if(Giorno.legalDate()){
        setYear(year);
        setMonth(month);
        setDay(day);
        return true;
    }
    else
        return false;
}

int Date::setYear(int year){
    Date Giorno;
    Giorno.Month=getMonth();
    Giorno.Day=getDay();
    Giorno.Year=year;

    if(Giorno.legalDate()){
        Year=year;
        return 0;
    }
    else
        return 1;
}

int Date::setMonth(int month){
    Date Giorno;
    Giorno.Year=getYear();
    Giorno.Day=getDay();
    Giorno.Month=month;

    if(Giorno.legalDate()){
        Month=month;
        return 0;
    }
    else
        return 1;
}

int Date::setDay(int day){
    Date Giorno;
    Giorno.Year=getYear();
    Giorno.Month=getMonth();
    Giorno.Day=day;

    if(Giorno.legalDate()){
        Day=day;
        return 0;
    }
    else
        return 1;
}

bool Date::legalDate() {
    int year=getYear(),month=getMonth(),day=getDay();
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