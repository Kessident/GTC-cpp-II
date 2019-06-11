//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 Ships

#ifndef LAB_6_SHIP_H
#define LAB_6_SHIP_H

#include <string>
#include <ostream>

class Ship {
protected:
    std::string name;
    std::string yearBuilt;
public:
    //Default
    Ship();
    //All
    Ship(const std::string &name, const std::string &yearBuilt);

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name_) {
        Ship::name = name_;
    }

    const std::string &getYearBuilt() const {
        return yearBuilt;
    }

    void setYearBuilt(const std::string &yearBuilt_) {
        Ship::yearBuilt = yearBuilt_;
    }

    virtual void print() const;

};


#endif //LAB_6_SHIP_H
