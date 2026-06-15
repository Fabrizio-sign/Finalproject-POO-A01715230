#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "Person.hpp"

class Passenger : public Person {
public:
    Passenger(const std::string& name, int id);
    std::string getRole() const override;
};

#endif
