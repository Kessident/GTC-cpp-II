//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 Ships

#include <iostream>
#include "Ship.h"
//Default
Ship::Ship() : name(), yearBuilt() {}
//All
Ship::Ship(const std::string &name, const std::string &yearBuilt) : name(name), yearBuilt(yearBuilt) {}

void Ship::print() const {
    std::cout << "Ship name: " << name << std::endl;
    std::cout << "Year built: " << yearBuilt << std::endl;
}
