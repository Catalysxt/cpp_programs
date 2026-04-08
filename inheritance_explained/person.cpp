#include <iostream>

#include "person.h"

Person::Person(std::string name) : m_name(name) {} // constructor

void Person::print() { std::cout << "My name is " << m_name << '\n'; }