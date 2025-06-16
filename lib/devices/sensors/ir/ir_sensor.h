#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <Arduino.h>
#include <Wire.h>

class IRSensor
{
private:
    int _inputPin;

public:
    IRSensor(int inputPin);
    float readDistanceMM();
    float readDistanceCM();
    bool isObstacle(int threshold);
};

#endif // IRSENSOR_H