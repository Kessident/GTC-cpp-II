//Charles Dodge
//CIST 2362 CRN 63228
//FInal Project - Airline Reservation System

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

    static bool sortByDepartingDesc(const Flight&, const Flight&);
    static bool sortByArrivingDesc(const Flight&, const Flight&);
    static bool sortByDepartTimeDesc(const Flight&, const Flight&);
    static bool sortByArrivalTimeDesc(const Flight&, const Flight&);
    static bool sortByFlightNumDesc(const Flight&, const Flight&);
    static bool sortByAirTypeDesc(const Flight&, const Flight&);
    static bool sortByFreqFlyMilesDesc(const Flight&, const Flight&);
    static bool sortByDepartingAsc(const Flight&, const Flight&);
    static bool sortByArrivingAsc(const Flight&, const Flight&);
    static bool sortByDepartTimeAsc(const Flight&, const Flight&);
    static bool sortByArrivalTimeAsc(const Flight&, const Flight&);
    static bool sortByFlightNumAsc(const Flight&, const Flight&);
    static bool sortByAirTypeAsc(const Flight&, const Flight&);
    static bool sortByFreqFlyMilesAsc(const Flight&, const Flight&);

    bool operator==(const int &rhs) const;
    bool operator!=(const int &rhs) const;

    bool operator==(const Flight &rhs) const;
    bool operator!=(const Flight &rhs) const;

    static map<string, string> availableCities;
};

#endif //FINAL_PROJECT_FLIGHT_H
