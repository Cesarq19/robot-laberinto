#include "encoder.h"

Encoder *Encoder::instances[4] = {nullptr};

Encoder::Encoder(int pinA, int pinB, float pulsesPerRevolution, float wheelRadius, int index)
{
    this->pinA = pinA;
    this->pinB = pinB;
    this->pulsesPerRevolution = pulsesPerRevolution;
    this->wheelRadius = wheelRadius;
    this->pulseCount = 0;

    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);

    lastStateA = digitalRead(pinA);
    if (index >= 0 && index < 4)
    {
        instances[index] = this;
        switch (index)
        {
        case 0:
            attachInterrupt(digitalPinToInterrupt(pinA), isrHandler0, CHANGE);
            break;
        case 1:
            attachInterrupt(digitalPinToInterrupt(pinA), isrHandler1, CHANGE);
            break;
        case 2:
            attachInterrupt(digitalPinToInterrupt(pinA), isrHandler2, CHANGE);
            break;
        case 3:
            attachInterrupt(digitalPinToInterrupt(pinA), isrHandler3, CHANGE);
            break;
        }
    }
}

void Encoder::update()
{
    int stateA = digitalRead(pinA);
    int stateB = digitalRead(pinB);

    if (stateA != lastStateA)
    {
        if (stateB != stateA)
        {
            pulseCount++;
        }
        else
        {
            pulseCount--;
        }
    }
    lastStateA = stateA;
}

long Encoder::getPulseCount()
{
    return pulseCount;
}

float Encoder::getVelocity(float dt)
{
    float revsPerSec = (pulseCount / pulsesPerRevolution) / dt;
    return 2 * M_PI * wheelRadius * revsPerSec;
}

float Encoder::getDistance()
{
    return (pulseCount / pulsesPerRevolution) * (2 * M_PI * wheelRadius);
}

void Encoder::isrHandler0()
{
    if (instances[0])
    {
        instances[0]->update();
    }
}
void Encoder::isrHandler1()
{
    if (instances[1])
    {
        instances[1]->update();
    }
}
void Encoder::isrHandler2()
{
    if (instances[2])
    {
        instances[2]->update();
    }
}
void Encoder::isrHandler3()
{
    if (instances[3])
    {
        instances[3]->update();
    }
}
