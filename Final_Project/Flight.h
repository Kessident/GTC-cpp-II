//
// Created by Charles Dodge on 2019-06-27.
//

#ifndef FINAL_PROJECT_FLIGHT_H
#define FINAL_PROJECT_FLIGHT_H


#include <string>
#include <ostream>
#include <map>

using namespace std;

class Flight {
private:
    int flightID;
    string departingFrom;
    string arrivingAt;
    string departTime;
    string arrivalTime;
    int flightNum;
    char aircraftType;
    int freqFlyMiles;
public:

    Flight();
    Flight(int, const string &, const string &, const string &, const string &, int , char , int );
    Flight(const Flight&);

    int getFlightId() const {
        return flightID;
    }
    void setFlightId(int flightId) {
        flightID = flightId;
    }
    const string &getDepartingFrom() const {
        return departingFrom;
    }
    void setDepartingFrom(const string &departingFrom_) {
        this->departingFrom = departingFrom_;
    }
    const string &getArrivingAt() const {
        return arrivingAt;
    }
    void setArrivingAt(const string &arrivingAt_) {
        this->arrivingAt = arrivingAt_;
    }
    const string &getDepartTime() const {
        return departTime;
    }
    void setDepartTime(const string &departTime_) {
        this->departTime = departTime_;
    }
    const string &getArrivalTime() const {
        return arrivalTime;
    }
    void setArrivalTime(const string &arrivalTime_) {
        this->arrivalTime = arrivalTime_;
    }
    int getFlightNum() const {
        return flightNum;
    }
    void setFlightNum(int flightNum_) {
        this->flightNum = flightNum_;
    }
    char getAircraftType() const {
        return aircraftType;
    }
    void setAircraftType(char aircraftType_) {
        this->aircraftType = aircraftType_;
    }
    int getFreqFlyMiles() const {
        return freqFlyMiles;
    }
    void setFreqFlyMiles(int freqFlyMiles_) {
        this->freqFlyMiles = freqFlyMiles_;
    }


    friend ostream &operator<<(ostream &os, const Flight &flight);

    static bool sortByFlightID(const Flight&, const Flight&);
    static bool sortByDeparting(const Flight&, const Flight&);
    static bool sortByArriving(const Flight&, const Flight&);
    static bool sortByDepartTime(const Flight&, const Flight&);
    static bool sortByArrivalTime(const Flight&, const Flight&);
    static bool sortByFlightNum(const Flight&, const Flight&);
    static bool sortByAirType(const Flight&, const Flight&);
    static bool sortByFreqFlyMiles(const Flight&, const Flight&);

    static map<string, string> availableCities;
};

#endif //FINAL_PROJECT_FLIGHT_H
