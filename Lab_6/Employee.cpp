//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 TeamLeader
#include "Employee.h"
#include <ostream>

void Employee::setAll(string &name_, int empNumber_, string &hireDate_) {
    name = name_;
    empNumber = empNumber_;
    hireDate = hireDate_;
}

std::ostream &operator<<(std::ostream &os, const Employee &emp) {
    os << "Name: " << emp.name << endl;
    os << "Employee number: " << emp.empNumber << endl;
    os << "Hire date: " << emp.hireDate << endl;
    return os;
}