//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#ifndef MIDTERM_PROJECT_EXTDATETYPE_H
#define MIDTERM_PROJECT_EXTDATETYPE_H


#include <string>
#include "dateType.h"

class extDateType {
private:
    dateType dateAsNumeric;
    std::string dateAsString;
public:
    extDateType(int, int, int);
    void setDate(int, int, int);

    void printFullDateString();
    void printMonthYearString();
};

const static std::string monthString[13] {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
#endif //MIDTERM_PROJECT_EXTDATETYPE_H
