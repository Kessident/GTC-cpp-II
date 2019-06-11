//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 Ships

#include <iostream>
#include "CargoShip.h"

//Default
CargoShip::CargoShip() :Ship(), cargoCapacity(0){}

//All
CargoShip::CargoShip(const std::string &name, const std::string &yearBuilt, int cargoCapacity) :
        Ship(name, yearBuilt), cargoCapacity(cargoCapacity) {}

void CargoShip::print() const {
    std::cout << "Ship name: " << name << std::endl;
    std::cout << "Cargo Capacity: " << cargoCapacity << std::endl;
}