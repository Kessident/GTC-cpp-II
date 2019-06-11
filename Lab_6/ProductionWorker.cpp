//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 TeamLeader
#include "ProductionWorker.h"
#include <ostream>

void ProductionWorker::setAll(string &name_, int empNum_, string &hireDate_, int shift_, double payRate_) {
    Employee::setAll(name_, empNum_, hireDate_);
    shift = shift_;
    payRate = payRate_;
}

std::ostream &operator<<(std::ostream &os, const ProductionWorker &prodWork) {
    os << static_cast<const Employee &>(prodWork);
    os << "Shift: " << prodWork.shift << endl;
    os << "Pay rate: " << prodWork.payRate << endl;
    return os;
}
