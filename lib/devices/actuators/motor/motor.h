#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{
private:
    int _in1, _in2, _pwm, _stby;
    int _speed;
    bool _forward;

public:
    Motor(int in1, int in2, int pwm, int stby);

    void forward(int speed);
    void backward(int speed);
    void stop();
    void brake();
    void setSpeed(int speed);
    int getSpeed();
    void setForward(bool forward);
    bool getDirection();
    void enable();
    void disable();
};

#endif // MOTOR_H