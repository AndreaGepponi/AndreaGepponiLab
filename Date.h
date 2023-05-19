//
// Created by geppo on 19/05/2023.
//

#ifndef ANDREAGEPPONILAB_DATE_H
#define ANDREAGEPPONILAB_DATE_H
#include <string>
class Date{
public:
    Date()=default;

    int getYear() const {
        return Year;
    }

    void setYear(int year) {
        Year = year;
    }

    int getMonth() const {
        return Month;
    }

    void setMonth(int month) {
        Month = month;
    }

    int getDay() const {
        return Day;
    }

    void setDay(int day) {
        Day = day;
    }

    void show();

    int CheckDate(const Date& Data);

    void addDate();
private:
    int Year,Month,Day;
};
#endif //ANDREAGEPPONILAB_DATE_H
