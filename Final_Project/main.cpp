//Charles Dodge
//CIST 2362 CRN 63228
//FInal Project
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Flight.h"
#include "Reservation.h"

using namespace std;

vector<Flight> flightList;
vector<Reservation> reservationList;

//Reads in flight and reservation information from 'flight-schedule.txt' and 'reservations.txt'
void initData();
void saveData();
void bookReservation();
void cancelReservation();
void displayBoardingPass();
void displayFlightSchedule();
void displayAvailableCities();
void listPassengers();

int main() {
    initData();

    int userChoice = 0;
    while (true) {
        cout << "-----Main Menu-----\n"
             << "1 - Book a new reservation\n"
             << "2 - Cancel a reservation\n"
             << "3 - Display a boarding pass\n"
             << "4 - Display the flight schedule\n"
             << "5 - Display available cities\n"
             << "6 - List all passengers on a flight\n"
             << "7 - Save reservation data\n"
             << "Anything else to exit: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                bookReservation();
                break;
            case 2:
                cancelReservation();
                break;
            case 3:
                displayBoardingPass();
                break;
            case 4:
                displayFlightSchedule();
                break;
            case 5:
                displayAvailableCities();
                break;
            case 6:
                listPassengers();
                break;
            case 7:
                saveData();
                break;
            default:
                saveData();
                return 0;

        }
    }
}

//Reads in Flight schedules and Reservations from files
void initData() {
    ifstream flightScheduleFile;
    flightScheduleFile.open("flight-schedule.txt", ios::in);

    Flight newFlight;

    int flightID;
    string departingFrom,
            arrivingAt,
            departTime,
            arrivalTime;
    int flightNum;
    char aircraftType;
    int freqFlyMiles;

    //Reads in flight information, stores flight in flightList
    while (!flightScheduleFile.eof()) {

        flightScheduleFile >> flightID;
        flightScheduleFile >> departingFrom;
        flightScheduleFile >> arrivingAt;
        flightScheduleFile >> departTime;
        flightScheduleFile >> arrivalTime;
        flightScheduleFile >> flightNum;
        flightScheduleFile >> aircraftType;
        flightScheduleFile >> freqFlyMiles;

        newFlight.setFlightId(flightID);
        newFlight.setDepartingFrom(departingFrom);
        newFlight.setArrivingAt(arrivingAt);
        newFlight.setDepartTime(departTime);
        newFlight.setArrivalTime(arrivalTime);
        newFlight.setFlightNum(flightNum);
        newFlight.setAircraftType(aircraftType);
        newFlight.setFreqFlyMiles(freqFlyMiles);

        flightList.push_back(newFlight);
    }

    flightScheduleFile.close();



    //Flight Reservation Information
    ifstream reservationsFile;
    reservationsFile.open("reservations.txt", ios::in);

    Reservation newRes;

    flightID = 0;
    string passengerName,
            seatAssignment;

    while (!reservationsFile.eof()) {
        reservationsFile >> flightID;
        getline(reservationsFile, passengerName, ',');
        getline(reservationsFile, seatAssignment, '\n');
        reservationsFile.get(); //Consume newline character

        newRes.setFlightId(flightID);
        newRes.setPassengerName(passengerName);
        newRes.setSeatAssignment(seatAssignment);

        reservationList.push_back(newRes);
    }

    reservationsFile.close();
}

//Saves Reservation data on user choice or quit
void saveData() {
//Save Reservation Information to "reservations.txt"
//###NAME,SEAT
}

//
void bookReservation() {
    //Departing city
    //Arrival city
    //Arrival Time - LATEST
    //Passenger name
//Your system must make sure that a flight is not overbook, and if a flight is booked it should suggest other flights to the same destination.
//Verify departing->arrival valid
//verify latest arrival time available
}

void cancelReservation() {
//Name
//Give choice of which to cancel
}

void displayBoardingPass() {
    //Flight Schedule
    //Seat Assignment

//The boarding pass should include the flight details including the seat number and the number of frequent flyer miles that can be earned.
}

void displayFlightSchedule() {
    cout << "1 to display all flight schedules\n"
         << "2 to sort flight schedules before displaying\n";
    int userChoice = 1;
    cin >> userChoice;

    if (userChoice == 2) {
        userChoice = 0;
        cout << "1 - sort of Departing City\n"
             << "2 - sort of Arrival City\n"
             << "3 - sort by Departure Time\n"
             << "4 - sort by Arrival Time\n"
             << "5 - sort by Flight Number\n"
             << "6 - sort by Aircraft Type\n"
             << "7 - sort by Frequent Flyer Miles\n";
        cin >> userChoice;
        while (cin.fail() || (userChoice < 1 || userChoice > 7)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid, try again: ";
            cin >> userChoice;
        }

        switch (userChoice) {
            case 1:
                sort(flightList.begin(), flightList.end(), Flight::sortByDeparting);
                break;
            case 2:
                sort(flightList.begin(), flightList.end(), Flight::sortByArriving);
                break;
            case 3:
                sort(flightList.begin(), flightList.end(), Flight::sortByDepartTime);
                break;
            case 4:
                sort(flightList.begin(), flightList.end(), Flight::sortByArrivalTime);
                break;
            case 5:
                sort(flightList.begin(), flightList.end(), Flight::sortByFlightNum);
                break;
            case 6:
                sort(flightList.begin(), flightList.end(), Flight::sortByAirType);
                break;
            case 7:
                sort(flightList.begin(), flightList.end(), Flight::sortByFreqFlyMiles);
                break;
        }


    }
}

void displayAvailableCities() {
//loop through Flight::availableCities
}

void listPassengers() {
//Display all flights, get choice, display all reservations with same flightID
}