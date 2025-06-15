#include "pid_controller.h"

PIDController::PIDController(float Kp, float Ki, float Kd, float outputMin, float outputMax, bool antiWindup)
{
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->outputMin = outputMin;
    this->outputMax = outputMax;
    this->antiWindup = antiWindup;
    this->prevError = 0;
    this->integral = 0;
}

float PIDController::compute(float setpoint, float measuredValue, float dt)
{
    float error = setpoint - measuredValue;

    float P = Kp * error;

    integral += error * dt;
    float I = Ki * integral;

    if (antiWindup)
    {
        if (I > outputMax)
            I = outputMax;
        if (I < outputMin)
            I = outputMin;
    }

    float derivative = (error - prevError) / dt;
    float D = Kd * derivative;

    prevError = error;

    float output = P + I + D;

    if (output > outputMax)
        output = outputMax;
    if (output < outputMin)
        output = outputMin;

    return output;
}

void PIDController::setTunings(float Kp, float Ki, float Kd)
{
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

void PIDController::setOutputLimits(float outputMin, float outputMax)
{
    this->outputMin = outputMin;
    this->outputMax = outputMax;
}

void PIDController::setAntiWindup(bool antiWindup)
{
    this->antiWindup = antiWindup;
}

void PIDController::reset()
{
    prevError = 0;
    integral = 0;
}
