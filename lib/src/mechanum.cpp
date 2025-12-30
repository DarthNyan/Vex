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
    drivespeed = { turn, turn, -turn, -turn };
    

    // forward-backward movement
    double move_fwd = move_speed * cos(move_dir - gyroHeading());
    drivespeed.lr += move_fwd;
    drivespeed.lf += move_fwd;
    drivespeed.rr += move_fwd;
    drivespeed.rf += move_fwd;

    // linear strafing
    // assumes wheels are mounted so that front reverse + rear forward moves left & vice versa
    double move_side = move_speed * sin(move_dir - gyroHeading());
    drivespeed.lr -= move_side;
    drivespeed.rr -= move_side;
    drivespeed.lf += move_side;
    drivespeed.rf += move_side;

    spinDriveMotors( drivespeed );
}

void
MechanumDrive::readController( ControllerAxes axes ) {
    deadZone( &axes );
    if ( axes.rx != 0 || axes.ry != 0 ) {    
        // Swap axes so that angle 0 is in front of driver, pi is behind.
        // + to right, - to left.
        last_heading = atan2(axes.rx, axes.ry);
    }
    if (axes.lx != 0 || axes.ly != 0 ) {
        move_dir = atan2(axes.lx, axes.ly);
    }
    move_speed = MOTOR_HIGH_VOLTAGE * axes.lx * axes.ly / ( CONTROLLER_AXIS_MAX * CONTROLLER_AXIS_MAX );
}