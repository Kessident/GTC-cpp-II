//
// Created by Charles Dodge on 2019-06-27.
//

#include "Reservation.h"

std::ostream &operator<<(std::ostream &os, const Reservation &r) {
    os << r.flightID << r.passengerName << "," << r.seatAssignment;
    return os;
}