//Charles Dodge
//CIST 2362 CRN 63228
//Lab 5 Day Of Year
#include <iostream>
#include "DayOfYear.h"

DayOfYear::DayOfYear(const int day){
    this->day = day;
    monthDay = this->day;

    //Walk through daysInMonth, if monthDay is larger than remove those days, check next.
    int index = 0;
    while (monthDay > daysInMonth[index]){
        monthDay -= daysInMonth[index];
        index++;
    }
    month = monthNames[index];
}

void DayOfYear::print() {
    std::cout << month << " " << monthDay;
}

const int DayOfYear::daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const std::string DayOfYear::monthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
