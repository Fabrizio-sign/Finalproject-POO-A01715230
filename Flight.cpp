#include "Flight.hpp"
#include <iostream>

Flight::Flight(int number, const std::string& dest, int seatCount)
    : flightNumber(number), destination(dest), totalSeats(seatCount) {
    for (int i = 1; i <= seatCount; ++i) {
        seats.push_back(Seat(i));
    }
}

int Flight::getFlightNumber() const {
    return flightNumber;
}

std::string Flight::getDestination() const {
    return destination;
}

bool Flight::reserveSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > totalSeats) return false;
    if (seats[seatNumber-1].getAvailability()) {
        seats[seatNumber-1].setAvailability(false);
        return true;
    }
    return false;
}

bool Flight::cancelSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > totalSeats) return false;
    if (!seats[seatNumber-1].getAvailability()) {
        seats[seatNumber-1].setAvailability(true);
        return true;
    }
    return false;
}

void Flight::displaySeats() const {
    std::cout << "Seats for flight " << flightNumber << ":\n";
    for (const auto& seat : seats) {
        std::cout << "Seat " << seat.getNumber() << ": "
                  << (seat.getAvailability() ? "Available" : "Reserved") << "\n";
    }
}

int Flight::getTotalSeats() const {
    return totalSeats;
}
