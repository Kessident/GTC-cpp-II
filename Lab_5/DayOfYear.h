//Charles Dodge
//CIST 2362 CRN 63228
//Lab 5 Day Of Year
#ifndef LAB_5_DAYOFYEAR_H
#define LAB_5_DAYOFYEAR_H

#include <string>


class DayOfYear {
private:
    int day;
    std::string month;
    int monthDay;

    static const int daysInMonth[12];
    static const std::string monthNames[12];

public:
    DayOfYear(int);

    void print();
};

#endif //LAB_5_DAYOFYEAR_H
