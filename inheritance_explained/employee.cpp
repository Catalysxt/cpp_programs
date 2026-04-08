#include <iostream>

#include "employee.h"

Employee::Employee(std::string name, std::string employer) : Person(name), m_employer(employer) {} // We call constructor of the base class

void Employee::print() {
    Person::print();
    std::cout << "I work at " << m_employer << '\n';
}