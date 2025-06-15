#include "imu.h"

IMU::IMU() : imu(Wire) {} // Inicializamos el objeto IMU con Wire

void IMU::begin()
{
    Wire.begin();
    imu.begin();
    imu.calcGyroOffsets(true); // Calibración automática
}

void IMU::readAccel(float &ax, float &ay, float &az)
{
    imu.update();
    ax = imu.getAccX();
    ay = imu.getAccY();
    az = imu.getAccZ();
}

void IMU::readGyro(float &gx, float &gy, float &gz)
{
    imu.update();
    gx = imu.getGyroX();
    gy = imu.getGyroY();
    gz = imu.getGyroZ();
}
