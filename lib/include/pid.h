#ifndef __PID_H
#define __PID_H

#include <functional>

// Computes a PID controller output over time given errors.
class PID {
public:
    PID( float kp, float ki, float kd, float i_thresh = 0, int d_period = 1 ) {
        KP = kp;
        KI = ki;
        KD = kd;
        I_thresh = ( i_thresh != 0 ) ? i_thresh : ki;
        D_period = d_period;

        integral = 0;
        derivative = 0;
        last_error = 0;
        cycle = 0;
    }
    PID() = default;

    float
    update( float error );

private:
    float KP;
    float KI;
    float KD;
    float I_thresh;
    int D_period;

    float integral;
    float derivative;
    float last_error;
    int cycle;
};

#endif