#include "YAxisController.hpp"

YAxisController::YAxisController()
{
}

YAxisController::YAxisController(int stepPin, int dirPin, int motorSpeed, int minTriggerPin, int maxTriggerPin)
{
    this->minTriggerPin = minTriggerPin;
    this->maxTriggerPin = maxTriggerPin;
}

YAxisController::~YAxisController()
{
}
void YAxisController::callibrate()
{
    while (this->minTriggerPin != 1)
    {
        this->stepperController.move(-1);
        this->stepperController.runSpeed();
        this->minTriggerPin = this->stepperController.currentPosition();
    }
    while (this->maxTriggerPin != 1)
    {
        this->stepperController.move(1);
        this->stepperController.runSpeed();
        this->maxTriggerPin = this->stepperController.currentPosition();
    }
}

void YAxisController::goTo(double position)
{
    double mappedPosition = map(position, -1, 1, this->minTriggerPin, this->maxTriggerPin);
    this->stepperController.moveTo(mappedPosition);
}
void YAxisController::setup()
{
    this->stepperController = AccelStepper(this->stepPin, this->dirPin);
    this->stepperController.setSpeed(this->motorSpeed);
    pinMode(this->minTriggerPin, INPUT);
    pinMode(this->maxTriggerPin, INPUT);
    pinMode(this->minTriggerPin, INPUT);
    pinMode(this->maxTriggerPin, INPUT);
}
void YAxisController::print()
{
    char buffer[40];
    sprintf(buffer, "YaxisController - minAbsPos:%d - maxAbsPos:%d  minTriggerPin:%d maxTriggerPin:%d ", minAbsPos, maxAbsPos, minTriggerPin, maxTriggerPin);
    Serial.println(buffer);
}