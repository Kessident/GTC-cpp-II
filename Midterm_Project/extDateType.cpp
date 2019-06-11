//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#include <iostream>
#include "extDateType.h"

void extDateType::setDate(int day, int month, int year) {
    dateAsNumeric = *new dateType(month, day, year);
    //Month Day, Year
    dateAsString = monthString[month] + " " + std::to_string(day) + ", " + std::to_string(year);
}

extDateType::extDateType(int month, int day, int year) {
    dateAsNumeric = *new dateType(month, day, year);
    //Month Day, Year
    dateAsString = monthString[month] + " " + std::to_string(day) + ", " + std::to_string(year);
}

void extDateType::printFullDateString() {
    std::cout << dateAsString;
}

void extDateType::printMonthYearString() {
    //Month Year
    std::cout << monthString[dateAsNumeric.getMonth()] << " " << std::to_string(dateAsNumeric.getYear());
}
