#include "CannonController.hpp"
CannonController::CannonController()
{
}

CannonController::CannonController(int enablePin1, int motor1Pin1, int motor1Pin2, int enablePin2, int motor2Pin1, int motor2Pin2)
{
    this->enablePin1 = enablePin1;
    this->enablePin2 = enablePin2;
    this->motor1Pin1 = motor1Pin1;
    this->motor1Pin2 = motor1Pin2;
    this->motor2Pin1 = motor2Pin1;
    this->motor2Pin2 = motor2Pin2;
    pinMode(this->enablePin1,OUTPUT);
    pinMode(this->enablePin2,OUTPUT);
    pinMode(this->motor1Pin1,OUTPUT);
    pinMode(this->motor1Pin2,OUTPUT);
    pinMode(this->motor2Pin1,OUTPUT);
    pinMode(this->motor2Pin2,OUTPUT);
}

CannonController::~CannonController()
{
}

void CannonController::shoot(double speed, double spin)
{
}