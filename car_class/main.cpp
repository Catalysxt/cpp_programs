#include <iostream>
#include "car.h"

//******************************************************************************
// Car Class
//
// Description: A simple program to demonstrate how classes work. << is overloaded
// to easily print class information

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main () {
    // Instantiate the class
    Car redHonda;
    // Print the class info
    std::cout << redHonda;

    // Let's move
    redHonda.accelerate(442);
    redHonda.turnLeft(12);

    // Print updated class info
    std::cout << redHonda;

    const Car blueBMW(316, 29); // Making a class object const
    
    std::cout << blueBMW;
}

//******************************************************************************
// Output

// Red honda speed: 0 km/hour, direction: 0 degrees
// Red honda speed: 200 km/hour, direction: 12 degrees
// Red honda speed: 316 km/hour, direction: 29 degrees

//******************************************************************************
