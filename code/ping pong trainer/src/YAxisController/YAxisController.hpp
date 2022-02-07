#ifndef Y_AXIS_CONTROLLER_H
#define Y_AXIS_CONTROLLER_H

#include <Arduino.h>
#include <AccelStepper.h>

class YAxisController : public AccelStepper
{
private:
public:
    double minAbsPos;
    double maxAbsPos;
    int stepPin;
    int dirPin;
    int minTriggerPin;
    int maxTriggerPin;
    YAxisController();
    YAxisController(int stepPin, int dirPin, int minTriggerPin, int maxTriggerPin);
    ~YAxisController();
    void callibrate();
    void goTo(double position);
    void print();
    void setup();
};
#endif