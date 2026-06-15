#include "Employee.hpp"

Employee::Employee(const std::string& name, int id)
    : Person(name, id) {}

std::string Employee::getRole() const {
    return "Employee";
}
