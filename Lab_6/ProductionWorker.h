//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 TeamLeader
#ifndef LAB_6_PRODUCTIONWORKER_H
#define LAB_6_PRODUCTIONWORKER_H

#include "Employee.h"

class ProductionWorker : protected Employee {
protected:
    int shift;
    double payRate;
public:
    //Default
    ProductionWorker() : Employee() {
        shift = 0;
        payRate = 0;
    }

    //All
    ProductionWorker(string &name_, int empNum_, string &hireDate_, int shift_, double payRate_) :
            Employee(name_, empNum_, hireDate_) {
        shift = shift_;
        payRate = payRate_;
    }

    int getShift() const {
        return shift;
    }

    void setShift(int shift_) {
        ProductionWorker::shift = shift_;
    }

    double getPayRate() const {
        return payRate;
    }

    void setPayRate(double payRate_) {
        ProductionWorker::payRate = payRate_;
    }

    void setAll(string &, int, string &, int, double);


    friend std::ostream &operator<<(std::ostream &, const ProductionWorker &);
};


#endif //LAB_6_PRODUCTIONWORKER_H
