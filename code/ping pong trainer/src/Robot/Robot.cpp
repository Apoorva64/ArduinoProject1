#include "Robot.hpp"
Robot::Robot()
{
    this->cannon = CannonController();
    this->yAxis = YAxisController(1, 2, 3, 4, 5);
    this->zRotation = RotationController(1, 2, 3);
    this->yRotation = RotationController(1, 2, 3);
    this->yAxis.print();
}
Robot::Robot(int stepPin, int dirPin, int motorSpeed, int minTriggerPin, int maxTriggerPin, int servoPinZ,
             int minLimitZ, int maxLimitZ, int servoPinY, int minLimitY, int maxLimitY)
{
    this->cannon = CannonController();
    this->yAxis = YAxisController(stepPin, dirPin, motorSpeed, minTriggerPin, maxTriggerPin);
    this->zRotation = RotationController(servoPinZ, minLimitZ, maxLimitZ);
    this->yRotation = RotationController(servoPinY, minLimitY, maxLimitY);
}

Robot::~Robot()
{
}

void Robot::shoot(double yTranslate, int yRotation, int zRotation, double speed, double spin)
{
    this->yAxis.goTo(yTranslate);
    this->yRotation.goTo(yRotation);
    this->zRotation.goTo(zRotation);
    this->cannon.shoot(speed, spin);
}

void Robot::attachServos()
{
    this->yRotation.attach();
    this->zRotation.attach();
}

void Robot::detachServos()
{
    this->yRotation.detach();
    this->zRotation.detach();
}
void Robot::setup()
{
    this->attachServos();
    this->yAxis.setup();
}