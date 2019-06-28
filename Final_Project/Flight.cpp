//
// Created by Charles Dodge on 2019-06-27.
//

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

Flight::Flight(int flightID_, const string &departingFrom_, const string &arrivingAt_, const string &departTime_, const string &arrivalTime_, int flightNum_, char aircraftType_, int freqFlyMiles_) {
    this->flightID = flightID_;
    this->departingFrom = departingFrom_;
    this->arrivingAt = arrivingAt_;
    this->departTime = departTime_;
    this->arrivalTime = arrivalTime_;
    this->flightNum = flightNum_;
    this->aircraftType = aircraftType_;
    this->freqFlyMiles = freqFlyMiles_;
}

Flight::Flight(const Flight & otherFlight) {
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
    os << flight.flightID << "," <<  flight.departingFrom << "," << flight.arrivingAt << "," <<  flight.departTime << "," <<  flight.arrivalTime
       << "," <<  flight.flightNum << "," <<  flight.aircraftType << "," << flight.freqFlyMiles;
    return os;
}


//Custom Sorting Function
bool Flight::sortByDeparting(const Flight &f1, const Flight &f2) {
    return f1.departingFrom > f2.departingFrom;
}

bool Flight::sortByArriving(const Flight &f1, const Flight &f2) {
    return f1.arrivingAt > f2.arrivingAt;
}

bool Flight::sortByDepartTime(const Flight &f1, const Flight &f2) {
    return f1.departTime > f2.departTime;
}

bool Flight::sortByArrivalTime(const Flight &f1, const Flight &f2) {
    return f1.arrivalTime > f2.arrivalTime;
}

bool Flight::sortByFlightNum(const Flight &f1, const Flight &f2) {
    return f1.flightNum > f2.flightNum;
}

bool Flight::sortByAirType(const Flight &f1, const Flight &f2) {
    return f1.aircraftType > f2.aircraftType;
}

bool Flight::sortByFreqFlyMiles(const Flight &f1, const Flight &f2) {
    return f1.freqFlyMiles > f2.freqFlyMiles;
}

map<string, string> Flight::availableCities = {
        {"Atlanta", "ATL"},
        {"Chicago", "CHI"},
        {"Dallas/Fort Worth", "DFW"},
        {"Hawaii", "HAW"},
        {"Los Angeles", "LAX"},
        {"New York City", "NYC"},
        {"Orlando", "ORL"}
};