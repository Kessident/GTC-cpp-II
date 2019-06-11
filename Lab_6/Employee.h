//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 TeamLeader
#ifndef LAB_6_EMPLOYEE_H
#define LAB_6_EMPLOYEE_H


#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int empNumber;
    string hireDate;
public:
//    Default
    Employee() {
        name = "";
        empNumber = 0;
        hireDate = "";
    }

//    All
    Employee(string &name_, int empNumber_, string &hireDate_) {
        name = name_;
        empNumber = empNumber_;
        hireDate = hireDate_;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name_) {
        Employee::name = name_;
    }

    int getEmpNumber() const {
        return empNumber;
    }

    void setEmpNumber(int empNumber_) {
        Employee::empNumber = empNumber_;
    }

    const string &getHireDate() const {
        return hireDate;
    }

    void setHireDate(const string &hireDate_) {
        Employee::hireDate = hireDate_;
    }

    void setAll(string &, int, string &);

    friend ostream &operator<<(ostream &, const Employee &);
};


#endif //LAB_6_EMPLOYEE_H
