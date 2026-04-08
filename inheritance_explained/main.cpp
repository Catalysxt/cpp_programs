#include <iostream>
#include "person.h"
#include "employee.h"
#include "student.h"

//******************************************************************************
// Inheritance Explained
//
// Description: This project explains inheritance with a simple inheritance 
// structure

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main() {

    Person Jessica("Jessica");
    Jessica.print();

    std::cout << '\n';
    Student Charles("Charles", "WSU");
    Charles.print();

    std::cout << '\n';
    Employee Jack("Jack", "Amazon");
    Jack.print();

    std::cout << '\n';
    Person *personPtr;
    personPtr = &Jack;
    personPtr->print(); // Method is called via "->" operator
}

//******************************************************************************
// Output

// My name is Jessica

// I attend WSU

// My name is Jack
// I work at Amazon

// My name is Jack
// I work at Amazon

//******************************************************************************
