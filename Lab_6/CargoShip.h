//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 Ships

#ifndef LAB_6_CARGOSHIP_H
#define LAB_6_CARGOSHIP_H

#include "Ship.h"
class CargoShip : public Ship{
protected:
    int cargoCapacity;
public:
    //Default
    CargoShip();
    //All
    CargoShip(const std::string &name, const std::string &yearBuilt, int cargoCapacity);

    int getCargoCapacity() const {
        return cargoCapacity;
    }

    void setCargoCapacity(int cargoCapacity_) {
        CargoShip::cargoCapacity = cargoCapacity_;
    }

    virtual void print() const;
};


#endif //LAB_6_CARGOSHIP_H
