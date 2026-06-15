#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
protected:
    std::string name;
    int id;

public:
    Person(const std::string& name, int id);
    virtual ~Person() = default;
    std::string getName() const;
    int getId() const;
    virtual std::string getRole() const = 0;
};

#endif
