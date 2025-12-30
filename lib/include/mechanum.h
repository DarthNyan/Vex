#ifndef __MECHANUM_H
#define __MECHANUM_H

#include "vexio.h"
#include "robot-middleware.h"
#include "pid.h"
#include <math.h>

class MechanumDrive {
public:
    MechanumDrive( PID _turn_pid ) {
        drivespeed = {0, 0, 0, 0};
        turn_pid = _turn_pid;
        last_heading = gyroHeading();
    }
    void
    move( ControllerAxes axes );

    void
    readController( ControllerAxes axes );

private:
    Drivespeed drivespeed;
    PID turn_pid;
    double last_heading;
    double move_dir;
    double move_speed;
};

#endif