#include "lib/mechanum.h"
#include "lib/robot-middleware.h"
#include <math.h>

void
MechanumDrive::move( ControllerAxes axes ) {
    
    // compute rotation
    readController( axes );
    float heading_error = last_heading - gyroHeading();
    // normalize error to [-pi, pi]
    heading_error = heading_error - (2 * M_PI ) * round( heading_error / ( 2 * M_PI ) );

    float turn = turn_pid.update( heading_error );

    // forward-backward movement
    float move_fwd = move_speed * cos(move_dir - gyroHeading());

    // linear strafing
    // assumes wheels are mounted so that front reverse + rear forward moves left & vice versa
    float move_side = move_speed * sin(move_dir - gyroHeading());

    drivespeed = {
        turn + move_fwd - move_side,
        turn + move_fwd + move_side,
        -turn + move_fwd + move_side,
        -turn + move_fwd - move_side
    };
    spinDriveMotors( drivespeed );
}

void
MechanumDrive::readController( ControllerAxes axes ) {
    deadZone( &axes, 20 );
    if ( axes.rx != 0 || axes.ry != 0 ) {    
        // Swap axes so that angle 0 is in front of driver, pi is behind.
        // + to right, - to left.
        last_heading = atan2(axes.rx, axes.ry);
    }
    if (axes.lx != 0 || axes.ly != 0 ) {
        move_dir = atan2(axes.lx, axes.ly);
    }
    move_speed = MOTOR_HIGH_VOLTAGE * (axes.lx * axes.lx + axes.ly * axes.ly );
    move_speed /= ( CONTROLLER_AXIS_MAX * CONTROLLER_AXIS_MAX );
}