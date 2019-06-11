//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#ifndef MIDTERM_PROJECT_EXTPERSONTYPE_H
#define MIDTERM_PROJECT_EXTPERSONTYPE_H

#include "PersonType.h"
#include "dateType.h"
#include "addressType.h"

using namespace std;

class extPersonType {
private:
    PersonType name; //string, string
    dateType date; //int month, int day, int year
    addressType address; //string, string, string, int
    std::string relation;
    std::string phoneNumber;
public:
    extPersonType(const string &firstName = "", const string &lastName = "",
            int month = 0, int day = 0, int year = 0,
            const string &street = "", const string &city = "", const string &state = "", int ZIP = 0,
            const string &relation = "", const string &phoneNumber = "");

    void setPersonalInfo(const string &firstName = "", const string &lastName = "",
                         int month = 0, int day = 0, int year = 0,
                         const string &street = "", const string &city = "", const string &state = "", int ZIP = 0,
                         const string &relation = "", const string &phoneNumber = "");

    const PersonType &getName() const;

    const dateType &getDate() const;

    const addressType &getAddress() const;

    const string &getRelation() const;

    const string &getPhoneNumber() const;

    void print() const;


    //
    //Relational Operators
    //
    bool operator<(const extPersonType &rhs) const;

    bool operator>(const extPersonType &rhs) const;

    bool operator<=(const extPersonType &rhs) const;

    bool operator>=(const extPersonType &rhs) const;
};

#endif //MIDTERM_PROJECT_EXTPERSONTYPE_H
