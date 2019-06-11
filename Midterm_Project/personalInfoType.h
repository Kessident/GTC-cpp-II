//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#ifndef MIDTERM_PROJECT_PERSONALINFOTYPE_H
#define MIDTERM_PROJECT_PERSONALINFOTYPE_H


#include <ostream>
#include "PersonType.h"
#include "dateType.h"

class personalInfoType {
protected:
    PersonType name;
    dateType bDay;
    int personID;
public:
    personalInfoType(std::string = "", std::string = "", int = 1, int = 1, int = 1990, int = 0);

    void setpersonalInfo(std::string, std::string, int, int, int, int);

    const PersonType &getName() const;

    const dateType &getBDay() const;

    int getPersonId() const;

    void printPersonalInfo() const;
};


#endif //MIDTERM_PROJECT_PERSONALINFOTYPE_H
