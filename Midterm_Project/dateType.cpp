//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#include <iostream>
#include "dateType.h"

//Constructor
dateType::dateType(int month, int day, int year) {
    checkDates(month, day, year);
    this->dMonth = month;
    this->dDay = day;
    this->dYear = year;
}

//Getters
int dateType::getMonth() const {
    return dMonth;
}

int dateType::getDay() const {
    return dDay;
}

int dateType::getYear() const {
    return dYear;
}

//Setter
void dateType::setDate(int dMonth_, int dDay_, int dYear_) {
    checkDates(dMonth_, dDay_, dYear_);

    dMonth = dMonth_;
    dDay = dDay_;
    dYear = dYear_;
}

void dateType::setMonth(int dMonth_) {
    dateType::dMonth = dMonth_;
}

void dateType::setDay(int dDay_) {
    dateType::dDay = dDay_;
}

void dateType::setYear(int dYear_) {
    dateType::dYear = dYear_;
}

//Print
void dateType::printDate() const {
    std::cout << "date is : " << dMonth << "-" << dDay << "-" << dYear << std::endl;
}

//Helpers
bool dateType::isLeapYear(int year) const{
    return year % 4 == 0;
}

//Throws exceptions if illegal dates
void dateType::checkDates(int month, int day, int year) {
    // month in range [1,12]
    if (month > 12 || month < 1) {
        throw IllegalDate(day, month);

        //day in range [1,31]
    } else if (day < 1 || day > 31) {
        throw IllegalDate(day, month);



        //check day not greater than number of days in month
    } else if (day > daysInMonths[month]) {
        //Check February on LeapYears
        if (isLeapYear(year) && month == 2 && day == 29) {//Only time day is greater than hardcoded num
            return;
        }
        throw IllegalDate(day, month);
    }

}



bool dateType::operator<(const dateType &rhs) const {
    if (dYear < rhs.dYear)
        return true;
    if (rhs.dYear < dYear)
        return false;
    if (dMonth < rhs.dMonth)
        return true;
    if (rhs.dMonth < dMonth)
        return false;
    return dDay < rhs.dDay;
}

bool dateType::operator>(const dateType &rhs) const {
    return rhs < *this;
}

bool dateType::operator<=(const dateType &rhs) const {
    return !(rhs < *this);
}

bool dateType::operator>=(const dateType &rhs) const {
    return !(*this < rhs);
}



bool dateType::isLeapYear() const {
    return isLeapYear(dYear);
}

int dateType::daysInMonth() const {
    return daysInMonths[dMonth];
}

int dateType::daysPassed() const {
    int daysSum = 0;
    //Sum of days in months passed
    for (int i = 0; i < dMonth; ++i) {
        daysSum += daysInMonths[i];
    }
    //Add days passed in current month
    daysSum += dDay;
    return daysSum;
}

int dateType::daysRemaining() const {
    return 365 - daysPassed();
}

void dateType::addDays(int daysToAdd) {
    dDay += daysToAdd;

    while (dDay > daysInMonths[dMonth]){
        dDay -= daysInMonths[dMonth];
        dMonth ++;
    }
}
