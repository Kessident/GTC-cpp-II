//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#include <iostream>
#include "extPersonType.h"

extPersonType::extPersonType(const string &firstName, const string &lastName,
                             int month, int day, int year,
                             const string &street, const string &city, const string &state, int ZIP,
                             const string &relation_, const string &phoneNumber_) {
    this->name = *new PersonType{firstName, lastName};
    this->date = *new dateType{month, day, year};
    this->address = *new addressType{street, city, state, ZIP};
    this->relation = relation_;
    this->phoneNumber = phoneNumber_;
};

void extPersonType::setPersonalInfo(const string &firstName, const string &lastName,
                                    int month, int day, int year,
                                    const string &street, const string &city, const string &state, int ZIP,
                                    const string &relation_, const string &phoneNumber_) {

    this->name = *new PersonType{firstName, lastName};
    this->date = *new dateType{month, day, year};
    this->address = *new addressType{street, city, state, ZIP};
    this->relation = relation_;
    this->phoneNumber = phoneNumber_;
}

const PersonType &extPersonType::getName() const {
    return name;
}

const dateType &extPersonType::getDate() const {
    return date;
}

const addressType &extPersonType::getAddress() const {
    return address;
}

const string &extPersonType::getRelation() const {
    return relation;
}

const string &extPersonType::getPhoneNumber() const {
    return phoneNumber;
};

void extPersonType::print() const {
    name.print();
    std::cout << "Birthday ";
    date.printDate();
    address.printAddress();
    std::cout << "Relation: " << relation << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
}

bool extPersonType::operator<(const extPersonType &rhs) const {
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    if (date < rhs.date)
        return true;
    if (rhs.date < date)
        return false;
    if (address < rhs.address)
        return true;
    if (rhs.address < address)
        return false;
    if (relation < rhs.relation)
        return true;
    if (rhs.relation < relation)
        return false;
    return phoneNumber < rhs.phoneNumber;
}

bool extPersonType::operator>(const extPersonType &rhs) const {
    return rhs < *this;
}

bool extPersonType::operator<=(const extPersonType &rhs) const {
    return !(rhs < *this);
}

bool extPersonType::operator>=(const extPersonType &rhs) const {
    return !(*this < rhs);
}
