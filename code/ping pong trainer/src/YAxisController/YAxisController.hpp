#ifndef Y_AXIS_CONTROLLER_H
#define Y_AXIS_CONTROLLER_H

#include <AccelStepper.h>
#include <Arduino.h>

class YAxisController
{
private:
    AccelStepper stepperController;

public:
    int minAbsPos;
    int maxAbsPos;
    int minTriggerPin;
    int maxTriggerPin;
    YAxisController();
    YAxisController(int stepPin, int dirPin, int motorSpeed, int minTriggerPin, int maxTriggerPin);
    ~YAxisController();
    void callibrate();
    void goTo(double position);
    void print();
};
#endif