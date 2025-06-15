#ifndef IMU_H
#define IMU_H

#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_tockn.h>

class IMU
{
private:
    MPU6050 imu;

public:
    IMU();
    void begin();
    void readAccel(float &ax, float &ay, float &az);
    void readGyro(float &gx, float &gy, float &gz);
};

#endif // IMU_H
