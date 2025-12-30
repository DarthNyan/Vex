#include "lib/robot-middleware.h"
#include "robot-config.h"


/*
 * To enable the writing of generic control code that is independent of robot specs ( or anything Vex-specific at-all ),
 * an abstraction is needed to connect the robot system with the code used to control it.
 * The functions in this file are defined in vexio.h and should be filled out on a per-robot basis
 * as the roboteur has configured motors and sensors on their machine.
*/
 
void
spinDriveMotors( Drivespeed drivespeed ) {
    Motor8.spin(forward, drivespeed.lf, volt);
    Motor9.spin(forward, drivespeed.rf, volt);
    Motor11.spin(forward, drivespeed.lr, volt);
    Motor20.spin(forward, drivespeed.rr, volt);
}

double
gyroHeading() {
    return 2 * M_PI * Gyro.heading(vex::rotationUnits::rev);
}

ControllerAxes
joysticks() {
    return {
        Controller1.Axis4.position(),
        Controller1.Axis3.position(),
        Controller1.Axis1.position(),
        Controller1.Axis2.position()
    };
}

int 
cpuTime() {
    return Brain.timer(msec);
}
