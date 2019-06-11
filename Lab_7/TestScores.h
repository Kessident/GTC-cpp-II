//Charles Dodge
//CIST 2362 CRN 63228
//Lab 7 TestScores

#ifndef LAB_7_TESTSCORES_H
#define LAB_7_TESTSCORES_H

#include <vector>
#include <string>

class TestScores {
private:
    std::vector<double> testScores;
public:
    class IllegalArgumentException : std::exception{
    private:
    double value;
    std::string msg;
    public:
        IllegalArgumentException(double value);
        double getValue(){return value;};
    };

    TestScores(std::vector<double> testScores);

    void verifyScore();

    double getAverage();
};


#endif //LAB_7_TESTSCORES_H
