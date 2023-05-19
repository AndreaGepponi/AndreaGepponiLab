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

void Date::addDate(){
    int year,month,day;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    bool bisestile=false;

    cout<<"Insert yyyy/mm/dd:"<<endl;
    cout<<"Year:";cin>>year;

    if((year%4==0 && year%100!=0) || year%400==0)
        bisestile=true;

    cout<<"Month:";cin>>month;
    if(0<month && month<13){
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            cout<<"Day:";cin>>day;
            cout<<endl;
            if(day<1 || day>31){
                SetConsoleTextAttribute(hConsole,4);
                cout<<"ERROR|Value out of bound"<<endl;
                SetConsoleTextAttribute(hConsole,7);
                addDate();
                return;
            }
        }
        else if(month==4||month==6||month==9||month==11){
            cout<<"Day:";cin>>day;
            cout<<endl;
            if(day<1 || day>30){
                SetConsoleTextAttribute(hConsole,4);
                cout<<"ERROR|Value out of bound"<<endl;
                SetConsoleTextAttribute(hConsole,7);
                addDate();
                return;
            }
        }
        else if(bisestile){
            cout<<"Day:";cin>>day;
            cout<<endl;
            if(day<1 || day>29){
                SetConsoleTextAttribute(hConsole,4);
                cout<<"ERROR|Value out of bound"<<endl;
                SetConsoleTextAttribute(hConsole,7);
                addDate();
                return;
            }
        }
        else{
            cout<<"Day:";cin>>day;
            cout<<endl;
            if(day<1 || day>28){
                SetConsoleTextAttribute(hConsole,4);
                cout<<"ERROR|Value out of bound"<<endl;
                SetConsoleTextAttribute(hConsole,7);
                addDate();
                return;
            }
        }

        setYear(year);
        setMonth(month);
        setDay(day);
        return;
    }
    else{
        SetConsoleTextAttribute(hConsole,4);
        cout<<"ERROR|Value out of bound"<<endl;
        SetConsoleTextAttribute(hConsole,7);
        addDate();
        return;
    }
}