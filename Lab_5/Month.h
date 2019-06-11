//Charles Dodge
//CIST 2362 CRN 63228
//Lab 5 Month Class
#ifndef LAB_5_MONTH_H
#define LAB_5_MONTH_H


#include <string>
#include <iostream>

using namespace std;

class Month {
private:
    string name;
    int monthNumber;
    int static nameToNumber(const string&);
    string static numberToName(int);
public:
    Month(const string &name);

    Month();

    Month(int monthNumber);

    const string &getName() const;

    void setName(const string &name);

    int getMonthNumber() const;

    void setMonthNumber(int monthNumber);

    Month operator++();
    const Month operator++(int);

    Month operator--();
    const Month operator--(int);

    friend ostream &operator<<(ostream &, const Month &);
    friend istream &operator>>(istream &, Month &);


};

const static string MONTH_NAMES[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

#endif //LAB_5_MONTH_H
