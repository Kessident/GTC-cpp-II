//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#include <iostream>
#include "personalInfoType.h"
#include "PersonType.h"

personalInfoType::personalInfoType(std::string firstName, std::string lastName, int month, int day, int year, int idNum) {
    this->name = *new PersonType{std::move(firstName), std::move(lastName)};
    this->bDay = *new dateType{month, day, year};;
    this->personID = idNum;
}

void personalInfoType::setpersonalInfo(std::string firstName, std::string lastName, int month, int day, int year, int idNum) {
    this->name = *new PersonType{std::move(firstName), std::move(lastName)};
    this->bDay = *new dateType{month, day, year};;
    this->personID = idNum;
}

void personalInfoType::printPersonalInfo() const {
    name.print();
    std::cout << "Birthday "; bDay.printDate();
    std::cout << "personID: " << personID;
}

const PersonType &personalInfoType::getName() const {
    return name;
}

const dateType &personalInfoType::getBDay() const {
    return bDay;
}

int personalInfoType::getPersonId() const {
    return personID;
}
