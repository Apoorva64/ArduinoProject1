#include <Arduino.h>
#include "robot.hpp"


char BluetoothData;
double yTranslate;
int yRot;
int zRot;
double speed;
double spin;
#include <AccelStepper.h>

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT Commands");
  //cannon.shoot();
  setupRobot();
  // put your setup code here, to run once
  yAxis.runToNewPosition(yAxis.minAbsPos);
  yAxis.runToNewPosition(yAxis.maxAbsPos);
}

void loop()
{
  // Process any info coming from the bluetooth serial link
  if (Serial.available())
  {
    BluetoothData = Serial.read(); // Get next character from bluetooth
    switch (BluetoothData)
    {
    case 'Y':
      yRot = Serial.parseInt();
      yRotationController.goTo(yRot);
      break;
    case 'Z':
      zRot = Serial.parseInt();
      zRotationController.goTo(zRot);
      break;

    case 'T':
      yTranslate = Serial.parseInt() / 100.0;
      Serial.print("ytranslate: ");
      Serial.println(yTranslate);
      yAxis.goTo(yTranslate);
      break;
    case 'V':
      speed = Serial.parseInt();
      Serial.print("speed: ");
      Serial.println(speed);
      break;
    case 'S':
      spin = Serial.parseInt() / 100.0;
      Serial.print("spin: ");
      Serial.println(spin);
      break;
    case 'P':
      CadenceController.goTo(110);
      delay(500);
      CadenceController.goTo(180);
      delay(500);
      Serial.print("PEW");
      break;
    default:
      break;
  }
  yAxis.run();
  cannon.updateMotor(speed,spin);
}
