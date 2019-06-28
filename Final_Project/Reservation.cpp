//
// Created by Charles Dodge on 2019-06-27.
//

#include "Reservation.h"

std::ostream &operator<<(std::ostream &os, const Reservation &r) {
    os << r.flightID << r.passengerName << "," << r.seatAssignment;
    return os;
}

bool Reservation::sortByFlightID(const Reservation &r1, const Reservation &r2) {
    return r1.flightID > r2.flightID;
}

bool Reservation::sortBySeat(const Reservation &r1, const Reservation &r2) {
    return r1.seatAssignment > r2.seatAssignment;
}
