//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#include <iostream>
#include "PersonType.h"

using namespace std;

PersonType::PersonType(string firstName_, string lastName_) : firstName(move(firstName_)), lastName(move(lastName_)) {}

void PersonType::setName(std::string firstName_, std::string lastName_) {
    this->firstName = std::move(firstName_);
    this->lastName = std::move(lastName_);
}

const std::string &PersonType::getFirstName() const {
    return firstName;
}

const std::string &PersonType::getLastName() const {
    return lastName;
}

void PersonType::print() const {
    cout << "First name: " << firstName << " Last name: " << lastName << endl;
}

bool PersonType::operator<(const PersonType &rhs) const {
    if (lastName < rhs.lastName)
        return true;
    if (rhs.lastName < lastName)
        return false;
    return firstName < rhs.firstName;
}

bool PersonType::operator>(const PersonType &rhs) const {
    return rhs < *this;
}

bool PersonType::operator<=(const PersonType &rhs) const {
    return !(rhs < *this);
}

bool PersonType::operator>=(const PersonType &rhs) const {
    return !(*this < rhs);
}
