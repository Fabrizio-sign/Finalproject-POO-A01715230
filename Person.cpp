#include "Person.hpp"

Person::Person(const std::string& name, int id)
    : name(name), id(id) {}

std::string Person::getName() const {
    return name;
}

int Person::getId() const {
    return id;
}
