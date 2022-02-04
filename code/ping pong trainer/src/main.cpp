#include <Arduino.h>
#include "robot.hpp"

char BluetoothData;
int yTranslate;
int yRot;
int zRot;
double speed;
double spin;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT Commands");
  setupRobot();
  // put your setup code here, to run once:
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
      yTranslate = Serial.parseFloat();
      yAxis.goTo(yTranslate);
      break;
    case 'V':
      speed = Serial.parseInt();
    case 'S':
      spin = Serial.parseFloat();
    default:
      break;
    }
  }
}