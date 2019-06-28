//
// Created by Charles Dodge on 2019-06-27.
//

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
};


#endif //FINAL_PROJECT_RESERVATION_H
