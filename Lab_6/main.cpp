//Charles Dodge
//CIST 2362 CRN 63228
//Lab 6 Ships

#include <iostream>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

using namespace std;

int doContinue = 0;

int main() {
    do {
        const int NUM_SHIPS = 3;
        string shipName, cruiseName, cargoName;
        string yearBuiltShip, yearBuiltCruise, yearBuiltCargo;
        int cruisePassengers, cargoCapacity;
        cout << "Enter the name for a ship: ";
        cin >> shipName;
        cout << "Enter the year the ship was built: ";
        cin >> yearBuiltShip;

        cout << "Enter the name for a cruise ship: ";
        cin >> cruiseName;
        cout << "Enter the year the ship was built: ";
        cin >> yearBuiltCruise;
        cout << "How many passengers can this cruise ship carry: ";
        cin >> cruisePassengers;
        while (cin.fail() || cruisePassengers <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << "Please enter a number greater than 0: ";
            cin >> cruisePassengers;
        }

        cout << "Enter the name for a cargo ship: ";
        cin >> cargoName;
        cout << "Enter the year the ship was built: ";
        cin >> yearBuiltCargo;
        cout << "How many tons can this cargo ship carry: ";
        cin >> cargoCapacity;
        while (cin.fail() || cargoCapacity <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << "Please enter a number greater than 0: ";
            cin >> cargoCapacity;
        }


        Ship *ships[NUM_SHIPS]{
                new Ship{shipName, yearBuiltShip},
                new CruiseShip{cruiseName, yearBuiltCruise, cruisePassengers},
                new CargoShip{cargoName, yearBuiltShip, cargoCapacity}
        };

        for (Ship *ship : ships) {
            ship->print();
        }

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
    return 0;
}








/*
//Lab 6 TeamLeader
#include <iostream>
#include "TeamLeader.h"

using namespace std;

int doContinue = 0;

int main() {
    do {
        TeamLeader leader;
        string name, hireDate;
        int empNum, shift, reqHours, hoursCompleted;
        double payRate, monthlyBonus;

        cout << "Enter the team leader's name: ";
        cin >> name;

        cout << "Enter the team leader's Employee number: ";
        cin >> empNum;
        while (cin.fail() || empNum < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Team leader's employee number must be a number greater than 0: ";
            cin >> empNum;
        }

        cout << "Enter team leader's hire date: ";
        cin >> hireDate;

        cout << "Enter team leader's shift (1 for day, 2 for night): ";
        cin >> shift;
        while (cin.fail() || shift < 1 || shift > 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Shift must be 1 or 2: ";
            cin >> shift;
        }

        cout << "Enter team leader's pay rate: ";
        cin >> payRate;
        while (cin.fail() || payRate <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pay rate must be a number greater than 0: ";
            cin >> payRate;
        }

        cout << "Enter team leader's monthly bonus: ";
        cin >> monthlyBonus;
        while (cin.fail() || monthlyBonus < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Monthly bonus must be a non-negative number: ";
            cin >> monthlyBonus;
        }

        cout << "Enter team leader's number of required training hours: ";
        cin >> reqHours;
        while (cin.fail() || reqHours <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Required training hours must be a number greater than 0: ";
            cin >> reqHours;
        }

        cout << "Enter number of training hours team leader has completed: ";
        cin >> hoursCompleted;
        while (cin.fail() || hoursCompleted < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Training hours completed must be a non-negative number: ";
            cin >> hoursCompleted;
        }

        leader.setAll(name, empNum, hireDate, shift, payRate, monthlyBonus, reqHours, hoursCompleted);

        cout << "\n\nTeam Leader\n";
        cout << leader;

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
    return 0;
}*/