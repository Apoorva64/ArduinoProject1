#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include "CannonController/CannonController.hpp"
#include "RotationController/RotationController.hpp"
#include "YAxisController/YAxisController.hpp"

class Robot
{
private:
    CannonController cannon;
    YAxisController yAxis;
    RotationController zRotation;
    RotationController yRotation;

public:
    Robot();
    Robot(int stepPin, int dirPin, int motorSpeed, int minTriggerPin, int maxTriggerPin, int servoPinZ,
          int minLimitZ, int maxLimitZ, int servoPinY, int minLimitY, int maxLimitY);
    ~Robot();
    void shoot(double yTranslate, int yRotation, int zRotation, double speed, double spin);
    void setup();
    void attachServos();
    void detachServos();
};
#endif