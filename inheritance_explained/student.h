
#include <iostream>
#include "person.h"

class Student : public Person {
public:
    Student(std::string name, std::string university);
    void print() override;
private:
    std::string m_university;
    // We don't store the name. This occurs in the base class.
};