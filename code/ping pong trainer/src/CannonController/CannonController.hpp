#ifndef CANNON_CONTROLLER_H
#define CANNON_CONTROLLER_H
#include <Arduino.h>

class CannonController
{
public:
    int enablePin1;
    int motor1Pin1;
    int motor1Pin2;
    int enablePin2;
    int motor2Pin1;
    int motor2Pin2;
    CannonController();
    CannonController(int enablePin1,
                     int motor1Pin1,
                     int motor1Pin2,
                     int enablePin2,
                     int motor2Pin1,
                     int motor2Pin2);
    ~CannonController();
    void shoot(double speed, double spin);
};
#endif