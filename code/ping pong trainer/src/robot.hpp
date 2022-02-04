#include "RotationController/RotationController.hpp"
#include "YAxisController/YAxisController.hpp"
#include "CannonController/CannonController.hpp"

RotationController yRotationController(4, 544, 2400);
RotationController zRotationController(5, 544, 2400);
YAxisController yAxis(6, 7, 180, 8, 9);
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
}