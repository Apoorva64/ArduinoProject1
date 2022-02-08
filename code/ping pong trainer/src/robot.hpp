#include "RotationController/RotationController.hpp"
#include "CannonController/CannonController.hpp"
#include "YAxisController/YAxisController.hpp"

RotationController yRotationController(6, 544, 2400);
RotationController zRotationController(7, 544, 2400);

YAxisController yAxis(2,3,4,5);
CannonController cannon;

void shoot(double yTranslate, int yRot, int zRot, double speed, double spin)
{
    yAxis.goTo(yTranslate);
    yRotationController.goTo(yRot);
    zRotationController.goTo(zRot);
    cannon.shoot(speed, spin);
}

void attachServos()
{
    yRotationController.attach();
    zRotationController.attach();
}

void detachServos()
{
    yRotationController.detach();
    zRotationController.detach();
}
void setupRobot()
{
    attachServos();
    yAxis.setup();
    // yAxis.stepperController->setSpeed(100);
}