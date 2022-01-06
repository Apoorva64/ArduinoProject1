#include <Arduino.h>
#include <Servo.h>
#define HORIZONTAL_ROTATION_SERVO_PIN 5

Servo horisontal_rotation_servo;

void setup()
{
  Serial.begin(9600);
  horisontal_rotation_servo.attach(HORIZONTAL_ROTATION_SERVO_PIN);
  horisontal_rotation_servo.write(180);
}

void loop()
{
  // for (int i = 0; i < 180; i++)
  // {
  //   horisontal_rotation_servo.write(i);
  //   delay(10);
  // }
  horisontal_rotation_servo.write(90+50);
  // delay(100);
  // horisontal_rotation_servo.write(0);
  // delay(100);
  // Serial.println(horisontal_rotation_servo.read());
  //   horisontal_rotation_servo.write(2);

  // Serial.write("pewpewpew\n");
}