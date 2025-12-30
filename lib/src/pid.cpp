#include "lib/pid.h"
#include <math.h>

float
PID::update( float error ) {
    // update derivative only once every D_period cycles.
    cycle = ++cycle % D_period;
    if ( cycle == 0 ) {
        derivative = KD * (error - last_error);
        last_error = error;
    }

    // cap integral to signed threshold.
    integral += KI * error;
    if ( fabs( integral ) > I_thresh ) {
        integral = I_thresh * integral / fabs( integral );
    }

    return KP*error + integral + derivative;
}