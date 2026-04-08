#include <iostream> 
#include "car.h"


Car::Car() : m_speed(0), m_direction(0) { }

Car::Car(int speed, int direction) : m_speed(speed), m_direction(direction) { }

Car::~Car() {}; // Does nothing

int Car::getSpeed() const { return m_speed; }
int Car::getDirection() const { return m_direction; }

void Car::accelerate(int speed) {
    m_speed += speed;
    if (speed >= 200) m_speed = 200; // Limit speed
}
void Car::deaccelerate(int speed) {
    m_speed -= speed;
    if (m_speed <= 0) m_speed = 0; // Prevent negative speed
}
void Car::turnLeft(int degrees) {
        m_direction += degrees;
        m_direction %= 360; // equivalent to a = a % b

        if (m_direction < 0) m_direction += 360;
    }
void Car::turnRight(int degrees) {
    m_direction += degrees;
    m_direction %= 360; // Limit degrees to 360
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "Red honda speed: " << car.m_speed
       << " km/hour, direction: " << car.m_direction
       << " degrees" << '\n';
    return os;
}