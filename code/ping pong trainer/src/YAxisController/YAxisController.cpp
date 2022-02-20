#include "YAxisController.hpp"


double mapf(double x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

YAxisController::YAxisController()
{
}

YAxisController::YAxisController(int stepPin, int dirPin, int minTriggerPin, int maxTriggerPin) : AccelStepper(1, stepPin, dirPin)
{
    this->minTriggerPin = minTriggerPin;
    this->maxTriggerPin = maxTriggerPin;
    this->minAbsPos = -1000;
    this->maxAbsPos = 1000;
    this->stepPin = stepPin;
    this->dirPin = dirPin;
}

YAxisController::~YAxisController()
{
}
void YAxisController::callibrate()
{
    while (digitalRead(this->minTriggerPin) == 1)
    {
        move(-10);
        run();
        minAbsPos = currentPosition();
    }
    while (digitalRead(this->maxTriggerPin) == 1)
    {
        move(10);
        run();
        maxAbsPos = currentPosition();
    }
}

void YAxisController::goTo(double position)
{
    double mappedPosition = mapf(position , -1.00, 1.00, this->minAbsPos, this->maxAbsPos);
    moveTo(mappedPosition);
}
void YAxisController::setup()
{
    pinMode(this->minTriggerPin, INPUT_PULLUP);
    pinMode(this->maxTriggerPin, INPUT_PULLUP);
    pinMode(this->dirPin, OUTPUT);
    pinMode(this->stepPin, OUTPUT);
    setAcceleration(1000);
    setMaxSpeed(500);
    callibrate();
    Serial.print("max: ");
    Serial.println(this->maxAbsPos);
    Serial.print("min: ");
    Serial.println(minAbsPos);
}
void YAxisController::print()
{
    // char buffer[40];
    // sprintf(buffer, "YaxisController - minAbsPos:%d - maxAbsPos:%d  minTriggerPin:%d maxTriggerPin:%d ", minAbsPos, maxAbsPos, minTriggerPin, maxTriggerPin);
    // Serial.println(buffer);
}