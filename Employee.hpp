#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Person.hpp"

class Employee : public Person {
public:
    Employee(const std::string& name, int id);
    std::string getRole() const override;
};

#endif
