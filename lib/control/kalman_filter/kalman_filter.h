#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

class KalmanFilter
{
private:
    float _Q_angle;
    float _Q_bias;
    float _R_measure;

    float _angle;
    float _bias;
    float _rate;

    struct Matrix2x2
    {
        float data[2][2];
    } _COV_M;

public:
    KalmanFilter();
    float getAngle(float newAngle, float newRate, float dt);
};

#endif // KALMAN_FILTER_H
