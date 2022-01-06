#include <Stepper.h>
#include <Arduino.h>

#define HORIZONTAL_AXIS_STEPS_PER_REVOLUTION 800
#define HORIZONTAL_AXIS_MOTOR_SPEED 2

// initialize the stepper motor
Stepper horizontal_axis(HORIZONTAL_AXIS_STEPS_PER_REVOLUTION, 2, 3);

void setup()
{
  Serial.begin(9600);
  horizontal_axis.setSpeed(HORIZONTAL_AXIS_MOTOR_SPEED);
}

void loop()
{
  // move stepper
  horizontal_axis.step(HORIZONTAL_AXIS_STEPS_PER_REVOLUTION);
  horizontal_axis.step(-HORIZONTAL_AXIS_STEPS_PER_REVOLUTION);
}