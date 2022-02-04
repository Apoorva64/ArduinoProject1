#ifndef ROTATION_CONTROLLER_H
#define ROTATION_CONTROLLER_H

#include <Arduino.h>
#include <Servo.h>

class RotationController
{

public:
    int minLimit;
    int maxLimit;
    int servoPin;
    Servo servo;
    RotationController();
    RotationController(int servoPin, int minLimit, int maxLimit);
    ~RotationController();
    void attach();
    void detach();
    void goTo(int angle);
};

#endif