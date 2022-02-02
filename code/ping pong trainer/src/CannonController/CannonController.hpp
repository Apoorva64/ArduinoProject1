#ifndef CANNON_CONTROLLER_H
#define CANNON_CONTROLLER_H
#include <Arduino.h>

class CannonController
{
public:
    CannonController();
    ~CannonController();
    void shoot(double speed, double spin);
};
#endif