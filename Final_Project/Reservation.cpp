//
// Created by Charles Dodge on 2019-06-27.
//

#include "Reservation.h"

std::ostream &operator<<(std::ostream &os, const Reservation &r) {
    os << r.flightID << r.passengerName << "," << r.seatAssignment;
    return os;
}

bool Reservation::sortByFlightID(const Reservation &r1, const Reservation &r2) {
    return r1.flightID < r2.flightID;
}

bool Reservation::sortBySeat(const Reservation &r1, const Reservation &r2) {
    return r1.seatAssignment < r2.seatAssignment;
}
bool Reservation::sortByName(const Reservation &r1, const Reservation &r2) {
    return r1.passengerName < r2.passengerName;
}



bool Reservation::operator==(const std::string &rhs) const {
    return passengerName == rhs;
}

bool Reservation::operator!=(const std::string &rhs) const {
    return passengerName != rhs;
}

bool Reservation::operator==(const Reservation &rhs) const {
    return flightID == rhs.flightID &&
           passengerName == rhs.passengerName &&
           seatAssignment == rhs.seatAssignment;
}

bool Reservation::operator!=(const Reservation &rhs) const {
    return !(rhs == *this);
}
