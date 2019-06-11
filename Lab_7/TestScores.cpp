//Charles Dodge
//CIST 2362 CRN 63228
//Lab 7 TestScores

#include "TestScores.h"

TestScores::IllegalArgumentException::IllegalArgumentException(double value) : value(value) {
    msg = std::to_string(value) + " is not a valid test score";
}

TestScores::TestScores(std::vector<double> testScores_){
    testScores = std::move(testScores_);
    verifyScore();
}

double TestScores::getAverage() {
    double sum = 0;
    for (double d : testScores){
        sum += d;
    }
    return sum / testScores.size();
}

void TestScores::verifyScore() {
    for (double d : testScores){
        if (d < 0 || d > 100){
            throw IllegalArgumentException(d);
        }
    }
}