//Charles Dodge
//CIST 2362 CRN 63228
//Lab 5 Month Class
#include <iostream>
#include "Month.h"

using namespace std;

//
//Constructors
//
Month::Month() {
    name = "January";
    monthNumber = 1;
}

Month::Month(const string &name) {
    this->name = name;
    monthNumber = nameToNumber(name);
}

Month::Month(int monthNumber) {
    this->monthNumber = monthNumber;
    name = numberToName(monthNumber);
}

//
//Getters / Setters
//
const string &Month::getName() const {
    return name;
}

void Month::setName(const string &name) {
    Month::name = name;
}

int Month::getMonthNumber() const {
    return monthNumber;
}

void Month::setMonthNumber(int monthNumber) {
    Month::monthNumber = monthNumber;
}

//
//Overload ++/--
//
Month Month::operator++() {
    monthNumber++;
    if (monthNumber == 13) {
        monthNumber = 1;
    }
    name = numberToName(monthNumber);
    return *this;
}

const Month Month::operator++(int) {
    Month temp(monthNumber);
    monthNumber++;
    if (monthNumber == 13) {
        monthNumber = 1;
    }
    name = numberToName(monthNumber);
    return temp;
}

Month Month::operator--() {
    monthNumber--;
    if (monthNumber == 0) {
        monthNumber = 12;
    }
    name = numberToName(monthNumber);
    return *this;
}

const Month Month::operator--(int) {
    Month temp(monthNumber);
    monthNumber--;
    if (monthNumber == 0) {
        monthNumber = 12;
    }
    name = numberToName(monthNumber);
    return temp;
}

//
//Overload >>/<<
//
ostream &operator<<(ostream &os, const Month &month) {
    os << month.name << " is month " << month.monthNumber << endl;
    return os;
}

istream &operator>>(istream &os, Month &month) {
    cout << "Enter 1 to enter month by number, 2 to enter by name: ";
    int userInput;
    os >> userInput;

    //Validation integer 1-2
    while (os.fail() || userInput < 1 || userInput > 2){
        os.clear();
        os.ignore(10000, '\n');
        cout << "Enter 1 to enter month by number, 2 to enter by name: ";
        os >> userInput;
    }

    if (userInput == 1){
        cout << "Enter a number 1-12: ";
        os >> userInput;

        //validation integer 1-12
        while (os.fail() || userInput < 1 || userInput > 12){
            os.clear();
            os.ignore(10000, '\n');
            cout << "Enter a number 1-12: ";
            os >> userInput;
        }
        month.monthNumber = userInput;
        month.name = Month::numberToName(month.monthNumber);

    } else if (userInput == 2){
        string monthName;
        cout << "Enter a month name, first letter capitalized: ";
        os >> monthName;

        //validation entered string is in MONTH_NAMES
        while( find(begin(MONTH_NAMES), end(MONTH_NAMES), monthName) == end(MONTH_NAMES)) {
            cout << "Enter a month name, first letter capitalized: ";
            os >> monthName;
        }

        month.name = monthName;
        month.monthNumber = Month::nameToNumber(month.name);
    }


    return os;
}

//
//Helpers
//
int Month::nameToNumber(const string &name) {
    if (name == "January") {
        return 1;
    } else if (name == "February") {
        return 2;
    } else if (name == "March") {
        return 3;
    } else if (name == "April") {
        return 4;
    } else if (name == "May") {
        return 5;
    } else if (name == "June") {
        return 6;
    } else if (name == "July") {
        return 7;
    } else if (name == "August") {
        return 8;
    } else if (name == "September") {
        return 9;
    } else if (name == "October") {
        return 10;
    } else if (name == "November") {
        return 11;
    } else if (name == "December") {
        return 12;
    }
    return 0;
}

string Month::numberToName(int monthNumber) {
    string name;
    switch (monthNumber) {
        case 1:
            name = "January";
            break;
        case 2:
            name = "February";
            break;
        case 3:
            name = "March";
            break;
        case 4:
            name = "April";
            break;
        case 5:
            name = "May";
            break;
        case 6:
            name = "June";
            break;
        case 7:
            name = "July";
            break;
        case 8:
            name = "August";
            break;
        case 9:
            name = "September";
            break;
        case 10:
            name = "October";
            break;
        case 11:
            name = "November";
            break;
        case 12:
            name = "December";
            break;
        default:
            name = "INVALID";
            break;
    }
    return name;
}