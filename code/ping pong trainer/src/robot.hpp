#include "RotationController/RotationController.hpp"
#include "CannonController/CannonController.hpp"
#include "YAxisController/YAxisController.hpp"

RotationController yRotationController(2, 544, 2400);
RotationController zRotationController(3, 544, 2400);
RotationController CadenceController(12,544,2400);
YAxisController yAxis(A0,A1,A2,A3);
CannonController cannon(5,8,9,6,10,11);

void shoot(double yTranslate, int yRot, int zRot, double speed, double spin)
{
    yAxis.goTo(yTranslate);
    yRotationController.goTo(yRot);
    zRotationController.goTo(zRot);
    cannon.updateMotor(speed, spin);
}

void attachServos()
{
    yRotationController.attach();
    zRotationController.attach();
    CadenceController.attach();

}

void detachServos()
{
    yRotationController.detach();
    zRotationController.detach();
    CadenceController.detach();
}
void setupRobot()
{
    attachServos();
    yAxis.setup();
    // yAxis.stepperController->setSpeed(100);
}