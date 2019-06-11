//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project
#include <iostream>
#include <string>
#include "PersonType.h"
#include "dateType.h"

using namespace std;

int doContinue = 0;

void testPersonType();

void testDateType();

int main() {
    do {
//        testPersonType();
//        testDateType();

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
    return 0;
}


void testPersonType() {
    string fName, lName;
    cout << "Enter first name: ";
    cin >> fName;

    cout << "Enter last name: ";
    cin >> lName;

    PersonType test{fName, lName};

    test.print();
}

void testDateType() {
    int day, month, year;
    cout << "Enter a day (numeric): ";
    cin >> day;

    cout << "Enter a month (numeric): ";
    cin >> month;

    cout << "Enter a year (numeric): ";
    cin >> year;

    dateType date;

    bool dateDidFail = true;
    while (dateDidFail) {
        try {
            date.setDate(month, day, year);
            dateDidFail = false;
        } catch (dateType::IllegalDate &ex) {
            cout << ex.getMsg();
            cout << "\nEnter a day (numeric): ";
            cin >> day;

            cout << "Enter a month (numeric): ";
            cin >> month;

            cout << "Enter a year (numeric): ";
            cin >> year;
        }

    }
    date.printDate();
}