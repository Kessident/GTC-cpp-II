//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 Ships

#ifndef LAB_6_CRUISESHIP_H
#define LAB_6_CRUISESHIP_H


#include "Ship.h"

class CruiseShip : public Ship {
protected:
    int numPassengers;
public:
    //Default
    CruiseShip();
    //All
    CruiseShip(const std::string &name, const std::string &yearBuilt, int numPassengers);

    int getNumPassengers() const {
        return numPassengers;
    }

    void setNumPassengers(int numPassengers_) {
        CruiseShip::numPassengers = numPassengers_;
    }

    virtual void print() const;
};


#endif //LAB_6_CRUISESHIP_H
