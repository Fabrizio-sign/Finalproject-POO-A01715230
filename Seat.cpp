#include "Seat.hpp"

Seat::Seat(int number) : seatNumber(number), isAvailable(true) {}

int Seat::getNumber() const {
    return seatNumber;
}

bool Seat::getAvailability() const {
    return isAvailable;
}

void Seat::setAvailability(bool available) {
    isAvailable = available;
}
