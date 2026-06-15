#include "Passenger.hpp"

Passenger::Passenger(const std::string& name, int id)
    : Person(name, id) {}

std::string Passenger::getRole() const {
    return "Passenger";
}
