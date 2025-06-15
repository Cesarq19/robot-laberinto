#ifndef ODOM_H
#define ODOM_H

#include <Arduino.h>
#include "encoder/encoder.h"
#include "imu/imu.h"

class Odom
{
private:
    Encoder *_leftEncoder;
    Encoder *_rightEncoder;
    IMU *_imu;
    float _wheelSeparation;
    float x, y, theta;
    float alpha;
    unsigned long lastTime;

public:
    Odom(Encoder *leftEncoder, Encoder *rightEncoder, IMU *imu, float wheelSeparation);
    void update();
    float getX();
    float getY();
    float getTheta();
    void reset();
};

#endif // ODOM_H
