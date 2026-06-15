#include "Reservation.hpp"
#include "Passenger.hpp"
#include "Flight.hpp"

Reservation::Reservation(Passenger* p, Flight* f, int seatNum)
    : passenger(p), flight(f), seatNumber(seatNum) {}

Passenger* Reservation::getPassenger() const {
    return passenger;
}

Flight* Reservation::getFlight() const {
    return flight;
}

int Reservation::getSeatNumber() const {
    return seatNumber;
}
