//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 TeamLeader
#include "TeamLeader.h"
#include <ostream>

void
TeamLeader::setAll(string &name_, int empNum_, string &hireDate_, int shift_, double payRate_, double monthlyBonus_, int reqTrainingHours_, int hoursCompleted_) {
    ProductionWorker::setAll(name_, empNum_, hireDate_, shift_, payRate_);
    monthlyBonus = monthlyBonus_;
    reqHours = reqTrainingHours_;
    hoursCompleted = hoursCompleted_;
}

std::ostream &operator<<(std::ostream &os, const TeamLeader &lead) {
    os << static_cast<const ProductionWorker &>(lead);
    os << "Monthly bonus: " << lead.monthlyBonus << endl;
    os << "Training hours required: " << lead.reqHours << endl;
    os << "Training hours completed: " << lead.hoursCompleted << endl;
    return os;
}

