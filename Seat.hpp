#ifndef SEAT_HPP
#define SEAT_HPP

#include <string>

class Seat {
private:
    int seatNumber;
    bool isAvailable;

public:
    Seat(int number);
    int getNumber() const;
    bool getAvailability() const;
    void setAvailability(bool available);
};

#endif
