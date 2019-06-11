//Charles Dodge
//CIST 2362 CRN 63228
//Lab 7 Total Template

#include <iostream>
#include <vector>

using namespace std;

int doContinue = 0;

template<class T>
T total(T valuesToRead) {//get and sum values
    T sum = 0, currNum;
    for (int i = 1; i <= valuesToRead; i++) {
        cout << "Enter value " << i << ": ";
        cin >> currNum;
        sum += currNum;
    }
    return sum;
}

int main() {
    do {
        cout << "How many values would you like to enter ";
        int numValues = 0;
        cin >> numValues;

        cout << "Integers\n";
        cout << "----------\n";
        int intTotal = total(numValues);
        cout << "Total value entered: " << intTotal << endl << endl;

        cout << "Doubles\n";
        cout << "----------\n";
        double doubleTotal = total(static_cast<double>(numValues));
        cout << "Total value entered: " << doubleTotal << endl;

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
}


/*
//Lab 7 TestScores
#include <iostream>
#include <vector>
#include "TestScores.h"

using namespace std;

int doContinue = 0;

int main() {
    do {
        int numScores;
        cout << "How many test scores are there? ";
        cin >> numScores;
        while (cin.fail() || numScores < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a positive number: ";
            cin >> numScores;
        }

        vector<double> testScoresVector;
        double currNum;
        for (int i = 1; i <= numScores; ++i) {
            cout << "Enter score " << i << ": ";
            cin >> currNum;
            while (cin.fail() || currNum < 0 || currNum > 100) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a positive number between 0 and 100: ";
                cin >> currNum;
            }
            testScoresVector.push_back(currNum);
        }

        TestScores newScores = TestScores(testScoresVector);
        double averageTestScore = newScores.getAverage();
        cout << "Average test score: " << averageTestScore << endl;


        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
}*/








/*
//Lab 7 Absolute Value
#include <iostream>

using namespace std;

template <class T>
T absoluteValue(T value);

int doContinue = 0;
int main() {
    do {
        double userInput;
        cout << "Enter a number, this program will give you that number's absolute value: ";
        cin >> userInput;
        while (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << "Please enter a number: ";
            cin >> userInput;
        }

        cout << "|" << userInput << "| = " << absoluteValue(userInput) << endl;


        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);

    return 0;
}


template <class T>
T absoluteValue(T value){
    //if value negative, multiply by -1, otherwise return
    return value < 0 ? value * -1 : value;
}*/