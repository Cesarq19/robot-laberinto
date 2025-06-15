#include "odom.h"

Odom::Odom(Encoder *leftEncoder, Encoder *rightEncoder, IMU *imu, float wheelSeparation)
{
    _leftEncoder = leftEncoder;
    _rightEncoder = rightEncoder;
    _wheelSeparation = wheelSeparation;
    this->_imu = imu;
    x = 0;
    y = 0;
    theta = 0;
    alpha = alpha;
    lastTime = millis();
}

void Odom::update()
{
    unsigned long currentTime = millis();
    float dt = (currentTime - lastTime) / 1000.0;
    lastTime = currentTime;

    float leftVelocity = _leftEncoder->getVelocity(dt);
    float rightVelocity = _rightEncoder->getVelocity(dt);

    float linearVelocity = (leftVelocity + rightVelocity) / 2;
    float angularVelocity = (rightVelocity - leftVelocity) / _wheelSeparation;

    float imuTheta = 0;

    theta = alpha * (theta + angularVelocity * dt) + (1 - alpha) * imuTheta;

    x += linearVelocity * cos(theta) * dt;
    y += linearVelocity * sin(theta) * dt;

    if (theta > PI)
    {
        theta -= 2 * PI;
    }
    else if (theta <= -PI)
    {
        theta += 2 * PI;
    }
}

float Odom::getX()
{
    return x;
}

float Odom::getY()
{
    return y;
}

float Odom::getTheta()
{
    return theta;
}

void Odom::reset()
{
    x = 0;
    y = 0;
    theta = 0;
}
