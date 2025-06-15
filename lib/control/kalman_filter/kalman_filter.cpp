#include "kalman_filter.h"

KalmanFilter::KalmanFilter()
{
    _Q_angle = 0.001;
    _Q_bias = 0.003;
    _R_measure = 0.03;

    _angle = 0.0;
    _bias = 0.0;

    // Inicialización manual de la matriz
    _COV_M.data[0][0] = 0.0;
    _COV_M.data[0][1] = 0.0;
    _COV_M.data[1][0] = 0.0;
    _COV_M.data[1][1] = 0.0;
}

float KalmanFilter::getAngle(float newAngle, float newRate, float dt)
{
    _rate = newRate - _bias;
    _angle += dt * _rate;

    _COV_M.data[0][0] += dt * (dt * _COV_M.data[1][1] - _COV_M.data[0][1] - _COV_M.data[1][0] + _Q_angle);
    _COV_M.data[0][1] -= dt * _COV_M.data[1][1];
    _COV_M.data[1][0] -= dt * _COV_M.data[1][1];
    _COV_M.data[1][1] += _Q_bias * dt;

    float S = _COV_M.data[0][0] + _R_measure;
    float K[2];
    K[0] = _COV_M.data[0][0] / S;
    K[1] = _COV_M.data[1][0] / S;

    float y = newAngle - _angle;
    _angle += K[0] * y;
    _bias += K[1] * y;

    _COV_M.data[0][0] -= K[0] * _COV_M.data[0][0];
    _COV_M.data[0][1] -= K[0] * _COV_M.data[0][1];
    _COV_M.data[1][0] -= K[1] * _COV_M.data[0][0];
    _COV_M.data[1][1] -= K[1] * _COV_M.data[0][1];

    return _angle;
}
