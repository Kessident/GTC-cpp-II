//Charles Dodge
//CIST 2362 CRN 63228
//FInal Project - Airline Reservation System

#include "Flight.h"

Flight::Flight() {
    flightID = 0;
    departingFrom = "N/A";
    arrivingAt = "N/A";
    departTime = "N/A";
    arrivalTime = "N/A";
    flightNum = 0;
    aircraftType = '0';
    freqFlyMiles = 0;
};

Flight::Flight(int flightID_, const string &departingFrom_, const string &arrivingAt_, const string &departTime_,
               const string &arrivalTime_, int flightNum_, char aircraftType_, int freqFlyMiles_) {
    this->flightID = flightID_;
    this->departingFrom = departingFrom_;
    this->arrivingAt = arrivingAt_;
    this->departTime = departTime_;
    this->arrivalTime = arrivalTime_;
    this->flightNum = flightNum_;
    this->aircraftType = aircraftType_;
    this->freqFlyMiles = freqFlyMiles_;
}

Flight::Flight(const Flight &otherFlight) {
    this->flightID = otherFlight.flightID;
    this->departingFrom = otherFlight.departingFrom;
    this->arrivingAt = otherFlight.arrivingAt;
    this->departTime = otherFlight.departTime;
    this->arrivalTime = otherFlight.arrivalTime;
    this->flightNum = otherFlight.flightNum;
    this->aircraftType = otherFlight.aircraftType;
    this->freqFlyMiles = otherFlight.freqFlyMiles;
}

ostream &operator<<(ostream &os, const Flight &flight) {
    os << flight.flightID << "," << flight.departingFrom << "," << flight.arrivingAt << "," << flight.departTime << ","
       << flight.arrivalTime
       << "," << flight.flightNum << "," << flight.aircraftType << "," << flight.freqFlyMiles;
    return os;
}


//Custom Sorting Function
bool Flight::sortByDepartingDesc(const Flight &f1, const Flight &f2) {
    return f1.departingFrom > f2.departingFrom;
}

bool Flight::sortByArrivingDesc(const Flight &f1, const Flight &f2) {
    return f1.arrivingAt > f2.arrivingAt;
}

bool Flight::sortByDepartTimeDesc(const Flight &f1, const Flight &f2) {
    return f1.departTime > f2.departTime;
}

bool Flight::sortByArrivalTimeDesc(const Flight &f1, const Flight &f2) {
    return f1.arrivalTime > f2.arrivalTime;
}

bool Flight::sortByFlightNumDesc(const Flight &f1, const Flight &f2) {
    return f1.flightNum > f2.flightNum;
}

bool Flight::sortByAirTypeDesc(const Flight &f1, const Flight &f2) {
    return f1.aircraftType > f2.aircraftType;
}

bool Flight::sortByFreqFlyMilesDesc(const Flight &f1, const Flight &f2) {
    return f1.freqFlyMiles > f2.freqFlyMiles;
}

bool Flight::sortByDepartingAsc(const Flight &f1, const Flight &f2) {
    return f1.departingFrom < f2.departingFrom;
}

bool Flight::sortByArrivingAsc(const Flight &f1, const Flight &f2) {
    return f1.arrivingAt < f2.arrivingAt;
}

bool Flight::sortByDepartTimeAsc(const Flight &f1, const Flight &f2) {
    return f1.departTime < f2.departTime;
}

bool Flight::sortByArrivalTimeAsc(const Flight &f1, const Flight &f2) {
    return f1.arrivalTime < f2.arrivalTime;
}

bool Flight::sortByFlightNumAsc(const Flight &f1, const Flight &f2) {
    return f1.flightNum < f2.flightNum;
}

bool Flight::sortByAirTypeAsc(const Flight &f1, const Flight &f2) {
    return f1.aircraftType < f2.aircraftType;
}

bool Flight::sortByFreqFlyMilesAsc(const Flight &f1, const Flight &f2) {
    return f1.freqFlyMiles < f2.freqFlyMiles;
}

map<string, string> Flight::availableCities = {
        {"Atlanta",           "ATL"},
        {"Chicago",           "CHI"},
        {"Dallas/Fort Worth", "DFW"},
        {"Hawaii",            "HAW"},
        {"Los Angeles",       "LAX"},
        {"New York City",     "NYC"},
        {"Orlando",           "ORL"}
};

//Used to find a flight by flightNum
bool Flight::operator==(const int &rhs) const {
    return flightNum == rhs;
}
bool Flight::operator!=(const int &rhs) const {
    return flightNum != rhs;
}

bool Flight::operator==(const Flight &rhs) const {
    return flightID == rhs.flightID;
}
bool Flight::operator!=(const Flight &rhs) const {
    return !(rhs == *this);
}
