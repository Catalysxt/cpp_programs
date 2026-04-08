#ifndef CAR_H
#define CAR_H

#include <iostream> 

class Car {
public:
    ~Car();

    // Constructors
    Car();
    Car(int speed, int direction);

    // Getters
    int getSpeed() const;
    int getDirection() const;

    // Methods
    void accelerate(int speed);
    void deaccelerate(int speed);
    void turnLeft(int degrees);
    void turnRight(int degrees);

    friend std::ostream& operator<<(std::ostream& os, const Car& car);

private:
    int m_speed {};
    int m_direction {};
};

#endif
