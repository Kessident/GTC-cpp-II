//Charles Dodge
//CIST 2362 CRN 63228
//FInal Project - Airline Reservation System

#ifndef FINAL_PROJECT_RESERVATION_H
#define FINAL_PROJECT_RESERVATION_H


#include <string>
#include <ostream>

class Reservation {
private:
    int flightID;
    std::string passengerName;
    std::string seatAssignment;
public:
    Reservation() {
        flightID = 0;
        passengerName = "";
        seatAssignment = "";
    }

    Reservation(int flightId_, const std::string &passengerName_, const std::string &seatAssignment_) {
        this->flightID = flightId_;
        this->passengerName = passengerName_;
        this->seatAssignment = seatAssignment_;
    }

    int getFlightId() const { return flightID; }
    void setFlightId(int flightId_) { flightID = flightId_; }
    const std::string &getPassengerName() const { return passengerName; }
    void setPassengerName(const std::string &passengerName_) { this->passengerName = passengerName_; }
    const std::string &getSeatAssignment() const { return seatAssignment; }
    void setSeatAssignment(const std::string &seatAssignment_) { this->seatAssignment = seatAssignment_; }

    friend std::ostream &operator<<(std::ostream &, const Reservation &);

    static bool sortByFlightID(const Reservation&, const Reservation&);
    static bool sortBySeat(const Reservation &, const Reservation &);
    static bool sortByName(const Reservation &, const Reservation &);

    bool operator==(const std::string &rhs) const;
    bool operator!=(const std::string &rhs) const;

    bool operator==(const Reservation &rhs) const;

    bool operator!=(const Reservation &rhs) const;
};


#endif //FINAL_PROJECT_RESERVATION_H
