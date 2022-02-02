#include "RotationController.hpp"
RotationController::RotationController(int servoPin, int minLimit, int maxLimit)
{
    this->maxLimit = maxLimit;
    this->minLimit = minLimit;
    this->servoPin = servoPin;
}

RotationController::RotationController()
{
    this->maxLimit = 0;
    this->minLimit = 0;
    this->servoPin = 0;
}
RotationController::~RotationController()
{
}

void RotationController::attach()
{
    this->servo.attach(servoPin, minLimit, maxLimit);
}
void RotationController::detach()
{
    this->servo.detach();
}
void RotationController::goTo(int angle)
{
    this->servo.write(angle);
}