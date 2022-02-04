#ifndef Y_AXIS_CONTROLLER_H
#define Y_AXIS_CONTROLLER_H

#include <Arduino.h>
#include <AccelStepper.h>

class YAxisController
{
private:
    AccelStepper *stepperController;

public:
    int minAbsPos;
    int maxAbsPos;
    int minTriggerPin;
    int maxTriggerPin;
    int dirPin;
    int stepPin;
    int motorSpeed;
    YAxisController();
    YAxisController(int stepPin, int dirPin, int motorSpeed, int minTriggerPin, int maxTriggerPin);
    ~YAxisController();
    void callibrate();
    void goTo(double position);
    void print();
    void setup();
};
#endif