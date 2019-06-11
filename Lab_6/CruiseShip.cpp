//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 Ships

#include <iostream>
#include "CruiseShip.h"
//Default
CruiseShip::CruiseShip() : Ship(), numPassengers(0){}
//All
CruiseShip::CruiseShip(const std::string &name, const std::string &yearBuilt, int numPassengers) :
        Ship(name, yearBuilt), numPassengers(numPassengers) {}

void CruiseShip::print() const {
    std::cout << "Ship name: " << name << std::endl;
    std::cout << "Number of passengers: " << numPassengers << std::endl;
}