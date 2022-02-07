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
  setupRobot();
  // put your setup code here, to run once:
  // Zaxis.setMaxSpeed(200.0);
  // Zaxis.setAcceleration(100.0);
  

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
      // Serial.println(yTranslate);
      yAxis.goTo(yTranslate);
      break;
    case 'V':
      speed = Serial.parseInt() / 100.0;
      Serial.print("speed: ");
      Serial.println(speed);
      break;
    case 'S':
      spin = Serial.parseInt() / 100.0;
      Serial.print("spin: ");
      Serial.println(spin);
      break;
    default:
      break;
    }
  }
  // Zaxis.move(-10);
  // Zaxis.run();
  // Zaxis.runToNewPosition(500);
  // Zaxis.runToNewPosition(100);
  // Zaxis.runToNewPosition(120);
  // yAxis.move(-10);
  // yAxis.runToNewPosition(-1000);
  // yAxis.runToNewPosition(10);
  // Serial.print(yAxis.currentPosition());
  // Serial.print(" ");
  // Serial.println(yAxis.targetPosition());
  yAxis.run();
}