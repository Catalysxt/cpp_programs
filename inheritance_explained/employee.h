
#include <iostream>
#include "person.h"

class Employee : public Person {
public:
    Employee(std::string, std::string employer);
    void print() override;

private:
    std::string m_employer;
};