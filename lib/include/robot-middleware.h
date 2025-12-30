#ifndef __ROBOT_MIDDLEWARE_H
#define __ROBOT_MIDDLEWARE_H

#include "vexio.h"

#define MOTOR_HIGH_VOLTAGE 10.0

double
gyroHeading();

void
spinDriveMotors( Drivespeed drivespeed );

ControllerAxes
joysticks();

int
cpuTime();

#endif