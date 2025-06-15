#include "diff_drive.h"

DiffDrive::DiffDrive(Motor *leftMotor, Motor *rightMotor, float wheelSeparation, float wheelDiameter, float maxSpeed)
{
    _leftMotor = leftMotor;
    _rightMotor = rightMotor;
    _wheelSeparation = wheelSeparation;
    _wheelDiameter = wheelDiameter;
    _maxSpeed = maxSpeed;
}

void DiffDrive::move(float linearSpeed, float angularSpeed)
{
    float leftSpeed = linearSpeed - (angularSpeed * _wheelSeparation / 2);
    float rightSpeed = linearSpeed + (angularSpeed * _wheelSeparation / 2);

    if (leftSpeed > _maxSpeed)
    {
        leftSpeed = _maxSpeed;
    }
    else if (leftSpeed < -_maxSpeed)
    {
        leftSpeed = -_maxSpeed;
    }

    if (rightSpeed > _maxSpeed)
    {
        rightSpeed = _maxSpeed;
    }
    else if (rightSpeed < -_maxSpeed)
    {
        rightSpeed = -_maxSpeed;
    }

    int leftSpeedInt = map(leftSpeed, -_maxSpeed, _maxSpeed, -255, 255);
    int rightSpeedInt = map(rightSpeed, -_maxSpeed, _maxSpeed, -255, 255);

    if (leftSpeedInt >= 0)
    {
        _leftMotor->forward(leftSpeedInt);
    }
    else
    {
        _leftMotor->backward(-leftSpeedInt);
    }

    if (rightSpeedInt >= 0)
    {
        _rightMotor->forward(rightSpeedInt);
    }
    else
    {
        _rightMotor->backward(-rightSpeedInt);
    }
}

void DiffDrive::stop()
{
    _leftMotor->stop();
    _rightMotor->stop();
}