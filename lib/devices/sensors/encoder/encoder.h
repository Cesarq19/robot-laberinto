#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder
{
private:
    int pinA, pinB;
    volatile long pulseCount;
    float pulsesPerRevolution;
    float wheelRadius;
    int lastStateA;

    static Encoder *instances[4];

    static void isrHandler0();
    static void isrHandler1();
    static void isrHandler2();
    static void isrHandler3();

public:
    Encoder(int pinA, int pinB, float pulsesPerRevolution, float wheelRadius, int index);
    void update();
    long getPulseCount();
    float getDistance();
    float getVelocity(float dt);
};

#endif // ENCODER_H
