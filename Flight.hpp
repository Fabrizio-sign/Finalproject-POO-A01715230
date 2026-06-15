#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>
#include <vector>
#include "Seat.hpp"

class Flight {
private:
    int flightNumber;
    std::string destination;
    int totalSeats;
    std::vector<Seat> seats;

public:
    Flight(int number, const std::string& dest, int seatCount);
    int getFlightNumber() const;
    std::string getDestination() const;
    bool reserveSeat(int seatNumber);
    bool cancelSeat(int seatNumber);
    void displaySeats() const;
    int getTotalSeats() const;
};

#endif
