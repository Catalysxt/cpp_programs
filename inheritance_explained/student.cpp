#include <iostream>

#include "person.h"
#include "student.h"

Student::Student(std::string name, std::string university) : Person(name), m_university(university) {}
    // We call constructor of the base class

void Student::print() {
    std::cout << "I attend " << m_university << '\n';
}