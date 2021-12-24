#include <Arduino.h>
#include <Servo.h>
#define HORIZONTAL_ROTATION_SERVO_PIN 5

Servo horisontal_rotation_servo;


void setup()
{
  Serial.begin(9600);
  horisontal_rotation_servo.attach(HORIZONTAL_ROTATION_SERVO_PIN);
  horisontal_rotation_servo.write(89);
}

void loop()
{
  Serial.println(horisontal_rotation_servo.read());
  //   horisontal_rotation_servo.write(2);
  
  // Serial.write("pewpewpew\n");
}