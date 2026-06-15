#ifndef RESERVATION_HPP
#define RESERVATION_HPP

class Passenger;
class Flight;

class Reservation {
private:
    Passenger* passenger;
    Flight* flight;
    int seatNumber;

public:
    Reservation(Passenger* p, Flight* f, int seatNum);
    Passenger* getPassenger() const;
    Flight* getFlight() const;
    int getSeatNumber() const;
};

#endif
