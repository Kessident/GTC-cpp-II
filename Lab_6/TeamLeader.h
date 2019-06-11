//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 TeamLeader
#ifndef LAB_6_TEAMLEADER_H
#define LAB_6_TEAMLEADER_H

#include "ProductionWorker.h"

class TeamLeader : protected ProductionWorker {
protected:
    double monthlyBonus;
    int reqHours;
    int hoursCompleted;
public:
    //Default
    TeamLeader() : ProductionWorker() {
        monthlyBonus = 0;
        reqHours = 0;
        hoursCompleted = 0;
    }

    //All
    TeamLeader(string &name_, int empNum_, string &hireDate_, int shift_, double payRate_, double monthlyBonus_, int reqTrainingHours_, int hoursCompleted_) :
            ProductionWorker(name_, empNum_, hireDate_, shift_, payRate_) {
        monthlyBonus = monthlyBonus_;
        reqHours = reqTrainingHours_;
        hoursCompleted = hoursCompleted_;
    }

    double getMonthlyBonus() const {
        return monthlyBonus;
    }

    void setMonthlyBonus(double monthlyBonus_) {
        TeamLeader::monthlyBonus = monthlyBonus_;
    }

    int getReqTrainingHours() const {
        return reqHours;
    }

    void setReqTrainingHours(int reqTrainingHours_) {
        TeamLeader::reqHours = reqTrainingHours_;
    }

    int getHoursCompleted() const {
        return hoursCompleted;
    }

    void setHoursCompleted(int hoursCompleted_) {
        TeamLeader::hoursCompleted = hoursCompleted_;
    }

    void setAll(string &, int, string &, int, double, double, int, int);

    friend std::ostream &operator<<(std::ostream &, const TeamLeader &);
};


#endif //LAB_6_TEAMLEADER_H
