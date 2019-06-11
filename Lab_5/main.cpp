//Charles Dodge
//CIST 2362 CRN 63228
//Lab 5 Month Class
#include <iostream>
#include "Month.h"

using namespace std;
int doContinue = 0;

int main() {
    do {
        Month monthTheFirst;
        cin >> monthTheFirst;
        cout << monthTheFirst;

        cout << "postfix++" << endl;
        monthTheFirst++;
        cout << monthTheFirst;
        cout << "++prefix" << endl;
        ++monthTheFirst;
        cout << monthTheFirst;

        cout << "postfix--" << endl;
        monthTheFirst--;
        cout << monthTheFirst;
        cout << "--prefix" << endl;
        --monthTheFirst;
        cout << monthTheFirst;
        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
    } while (doContinue == 1);

    return 0;
}


/*
//Lab 5 Day Of Year
#include <iostream>
#include "DayOfYear.h"

using namespace std;

int doContinue = 0;

int main() {
    do {
        int day;
        cout << "Enter the day: ";
        cin >> day;
        while (cin.fail() || day < 1 || day > 365) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a number between 1 and 365: ";
            cin >> day;
        }

        DayOfYear DOY = (day);

        DOY.print();
        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
    } while (doContinue == 1);
    return 0;
}*/