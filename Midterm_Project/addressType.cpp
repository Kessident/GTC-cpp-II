//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#include <iostream>
#include "addressType.h"

addressType::addressType(const std::string &streetAddress, const std::string &city, const std::string &state, int zipCode)
: streetAddress(streetAddress), city(city), state(state), ZIPCode(zipCode) {}

void addressType::setAddress(const std::string &streetAddress_, const std::string &city_, const std::string &state_, int zipCode) {
    this->streetAddress = streetAddress_;
    this->city = city_;
    this->state = state_;
    this->ZIPCode = zipCode;
}

void addressType::printAddress() const {
    std::cout << streetAddress << std::endl;
    std::cout << city << ", " << state << ", " << ZIPCode << std::endl;

}

const std::string &addressType::getStreetAddress() const {
    return streetAddress;
}

const std::string &addressType::getCity() const {
    return city;
}

const std::string &addressType::getState() const {
    return state;
}

int addressType::getZipCode() const {
    return ZIPCode;
}

bool addressType::operator<(const addressType &rhs) const {
    //state, city, zip, address
    if (state < rhs.state)
        return true;
    if (rhs.state < state)
        return false;
    if (city < rhs.city)
        return true;
    if (rhs.city < city)
        return false;
    if (ZIPCode < rhs.ZIPCode)
        return true;
    if (rhs.ZIPCode < ZIPCode)
        return false;
    return streetAddress < rhs.streetAddress;
}

bool addressType::operator>(const addressType &rhs) const {
    return rhs < *this;
}

bool addressType::operator<=(const addressType &rhs) const {
    return !(rhs < *this);
}

bool addressType::operator>=(const addressType &rhs) const {
    return !(*this < rhs);
}
