#include "ir_sensor.h"

IRSensor::IRSensor(int _inputPin) : _inputPin(_inputPin)
{
    pinMode(_inputPin, INPUT);
}

float IRSensor::readDistanceMM()
{
    auto lecture = analogRead(_inputPin);
    return (float)lecture;
}

float IRSensor::readDistanceCM()
{
    float distanceMM = readDistanceMM();
    if (distanceMM > 0)
    {
        return distanceMM / 10.0;
    }
    return -1;
}

bool IRSensor::isObstacle(int threshold)
{
    float distance = readDistanceMM();
    return (distance > 0 && distance < threshold);
}