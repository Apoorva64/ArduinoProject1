#include "CannonController.hpp"
CannonController::CannonController()
{
}

CannonController::CannonController(int enablePin1, int motor1Pin1, int motor1Pin2, int enablePin2, int motor2Pin1, int motor2Pin2)
{
    this->enablePin1 = enablePin1;
    this->enablePin2 = enablePin2;
    this->motor1Pin1 = motor1Pin1;
    this->motor1Pin2 = motor1Pin2;
    this->motor2Pin1 = motor2Pin1;
    this->motor2Pin2 = motor2Pin2;
    this->motor2Pin2 = motor2Pin2;
    
    pinMode(this->enablePin1,OUTPUT);
    pinMode(this->enablePin2,OUTPUT);
    pinMode(this->motor1Pin1,OUTPUT);
    pinMode(this->motor1Pin2,OUTPUT);
    pinMode(this->motor2Pin1,OUTPUT);
    pinMode(this->motor2Pin2,OUTPUT);
}

CannonController::~CannonController()
{
}

void CannonController::updateMotor(double speed, double spin)
{
    if(spin<-0.5){
     digitalWrite(this->motor1Pin1,HIGH);
     digitalWrite(this->motor1Pin2,LOW);
     digitalWrite(this->motor2Pin1,LOW);
     digitalWrite(this->motor2Pin2,HIGH);
     analogWrite(this->enablePin1,speed);   
     analogWrite(this->enablePin2,speed*-0.4*spin);
    }
    else if(spin>0.5){
    digitalWrite(this->motor1Pin1,LOW);
    digitalWrite(this->motor1Pin2,HIGH);
    digitalWrite(this->motor2Pin1,HIGH);
    digitalWrite(this->motor2Pin2,LOW);
    analogWrite(this->enablePin1,speed*0.4*spin);   
    analogWrite(this->enablePin2,speed); 
    }
    else{
    digitalWrite(this->motor1Pin1,HIGH);
    digitalWrite(this->motor1Pin2,LOW);
    digitalWrite(this->motor2Pin1,HIGH);
    digitalWrite(this->motor2Pin2,LOW);
    analogWrite(this->enablePin1,constrain(speed*(1-spin),0,255));   
    analogWrite(this->enablePin2,constrain(speed*(1-spin),0,255)); 
    }
}
