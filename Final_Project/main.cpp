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

bool validateCity(const string &);

string convertCityToCode(const string &);

bool flightIsFull(const Flight &);

void bookReservationOnFlight(const string &, const Flight &);

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
        cin.get(); // Consume newline

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
    ofstream outputFile;
    outputFile.open("reservations.txt", ios::out);

    for (const auto &res : reservationList) {
        outputFile << setw(3) << setfill('0');
        outputFile << res << endl;
    }

    cout << "Reservations saved\n";
}

//Get Departing and Arrival City, arrival time optional, and Passenger name
//Book into first valid flight
void bookReservation() {
    string name, departing, arriving, time;
    cout << "Enter passenger's name: ";
    getline(cin, name, '\n');

    cout << "What city are we departing from?\n"
         << "Enter city code or full name: ";
    getline(cin, departing, '\n');

    while (!validateCity(departing)) {
        cout << "Invalid entry: ";
        getline(cin, departing, '\n');
    }


    cout << "What city are we arriving at?\n"
         << "Enter city code or full name: ";
    getline(cin, arriving, '\n');

    while (!validateCity(arriving)) {
        cout << "Invalid entry: ";
        getline(cin, arriving, '\n');
    }


    cout << "Enter requested arrival time, 0 if arrival time does not matter\n"
         << "24 hr format, ##:##\n";
    getline(cin, time, '\n');
    //Validate time format

    string departingCode, arrivingCode;
    departingCode = convertCityToCode(departing);
    arrivingCode = convertCityToCode(arriving);

    vector<Flight> possibleFlights;
    for (const Flight &flight : flightList) {
        if (flight.getDepartingFrom() == departingCode && flight.getArrivingAt() == arrivingCode) {

            //Check that arrival time of flight is later than requested, if requested
            if (time != "0" || flight.getArrivalTime() > time) {
                possibleFlights.push_back(flight);
            }
        }
    }


    for (const Flight &f : possibleFlights) {
        if (!flightIsFull(f)) {
            bookReservationOnFlight(name, f);
        }
    }


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

//TODO Actually Display Schedule
    }
}

void displayAvailableCities() {
//loop through Flight::availableCities
}

void listPassengers() {
//Display all flights, get choice, display all reservations with same flightID
}

//
//Helpers
//

//Validates that a given string is a valid city for departures or arrivals
bool validateCity(const string &city) {
    bool isValid = false;
    for (const auto &cities : Flight::availableCities) {
        //Checks against both city code and full name
        if (city == cities.first || city == cities.second) {
            isValid = true;
        }
    }

    return isValid;
}

//Returns city code of cities
string convertCityToCode(const string &city) {
    if (city.length() == 3)
        return city;
    auto it = Flight::availableCities.find(city);
    return it->second;
}

bool flightIsFull(const Flight &flight) {
    int reservationsOnFlight = 0;

    for (const Reservation &r : reservationList) {
        if (r.getFlightId() == flight.getFlightId())
            reservationsOnFlight++;
    }

    if (flight.getAircraftType() == 'A') {
        //20 possible seats on type 'A'
        return reservationsOnFlight == 20;

    } else {
        //15 possible seats on type 'B'
        return reservationsOnFlight == 15;
    }
}

void bookReservationOnFlight(const string &name, const Flight &flight) {
    Reservation newRes(flight.getFlightId(), name, "");

    vector<Reservation> reservationsOnFlight;

    for (const Reservation r : reservationList) {
        if (r.getFlightId() == flight.getFlightId()) {
            reservationsOnFlight.push_back(r);
        }
    }

    if (reservationsOnFlight.empty()) {
        newRes.setSeatAssignment("1A");


    } else {
        sort(reservationsOnFlight.begin(), reservationsOnFlight.end(), Reservation::sortBySeat);

        //Last reservation
        string lastSeat = (*(reservationsOnFlight.end() - 1)).getSeatAssignment();
        string newSeat;

        switch (lastSeat[1]) {
            case 'A':
                newSeat = to_string(lastSeat[0]) + 'B';
                break;
            case 'B':
                newSeat = to_string(lastSeat[0]) + 'C';
                break;
            case 'C':
                if (flight.getAircraftType() == 'B') {
                    newSeat = to_string(lastSeat[0] + 1) + 'A';
                } else {
                    newSeat = to_string(lastSeat[0]) + 'D';
                }
                break;
            case 'D':
                newSeat = to_string(lastSeat[0] + 1) + 'A';
                break;
        }
    }


    reservationList.push_back(newRes);
}