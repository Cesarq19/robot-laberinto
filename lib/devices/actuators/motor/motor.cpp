#include "motor.h"

Motor::Motor(int in1, int in2, int pwm, int stby)
{
    _in1 = in1;
    _in2 = in2;
    _pwm = pwm;
    _stby = stby;
    _speed = 0;
    _forward = true;

    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_pwm, OUTPUT);
    pinMode(_stby, OUTPUT);

    digitalWrite(_stby, HIGH);
}

void Motor::forward(int speed)
{
    _speed = speed;
    _forward = true;
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
    analogWrite(_pwm, speed);
}

void Motor::backward(int speed)
{
    _speed = speed;
    _forward = false;
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
    analogWrite(_pwm, speed);
}

void Motor::stop()
{
    analogWrite(_pwm, 0);
}

void Motor::brake()
{
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, HIGH);
    analogWrite(_pwm, 0);
}

void Motor::setSpeed(int speed)
{
    _speed = speed;
    analogWrite(_pwm, speed);
}

int Motor::getSpeed()
{
    return _speed;
}

void Motor::setForward(bool forward)
{
    _forward = forward;
    digitalWrite(_in1, forward ? HIGH : LOW);
    digitalWrite(_in2, forward ? LOW : HIGH);
}

bool Motor::getDirection()
{
    return _forward;
}

void Motor::enable()
{
    digitalWrite(_stby, HIGH);
}

void Motor::disable()
{
    digitalWrite(_stby, LOW);
}