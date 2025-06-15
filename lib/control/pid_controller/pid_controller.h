#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController
{
private:
    float Kp, Ki, Kd;
    float prevError;
    float integral;
    float outputMin, outputMax;
    bool antiWindup;

public:
    PIDController(float Kp, float Ki, float Kd, float outputMin, float outputMax, bool antiWindup = true);
    float compute(float setpoint, float measuredValue, float dt);
    void setTunings(float Kp, float Ki, float Kd);
    void setOutputLimits(float outputMin, float outputMax);
    void setAntiWindup(bool antiWindup);
    void reset();
};

#endif // PID_CONTROLLER_H