#ifndef ANDREAGEPPONILAB_DATE_H
#define ANDREAGEPPONILAB_DATE_H
#include <string>
#include <iostream>
using namespace std;
class Date{
public:
    Date()=default;

    int getYear() const {
        return Year;
    }

    int setYear(int year);

    int getMonth() const {
        return Month;
    }

    int setMonth(int month);

    int getDay() const {
        return Day;
    }

    int setDay(int day);

    void show() const;

    int CheckDate() const;

    bool addDate(int year, int month, int day);

    bool legalDate() const;
private:
    int Year=0,Month=1,Day=1;
};
#endif //ANDREAGEPPONILAB_DATE_H
