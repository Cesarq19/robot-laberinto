#ifndef DIFF_DRIVE_H
#define DIFF_DRIVE_H

#include <Arduino.h>
#include "motor/motor.h"

class DiffDrive
{
private:
    Motor *_leftMotor;
    Motor *_rightMotor;
    float _wheelSeparation;
    float _wheelDiameter;
    float _maxSpeed;

public:
    DiffDrive(Motor *leftMotor, Motor *rightMotor, float wheelSeparation, float wheelDiameter, float maxSpeed);
    void move(float linearSpeed, float angularSpeed);
    void stop();
};

#endif // DIFF_DRIVE_H