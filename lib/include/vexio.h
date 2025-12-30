#ifndef __VEXIO_H
#define __VEXIO_H

#define CONTROLLER_AXIS_MAX 100
typedef struct {
    int lx;
    int ly;
    int rx;
    int ry;
} ControllerAxes;

void 
deadZone( ControllerAxes* axes, 
          int lthresh = CONTROLLER_AXIS_MAX/2,
          int rthresh = CONTROLLER_AXIS_MAX/2 );

typedef struct {
    float lr;
    float lf;
    float rr;
    float rf;
} Drivespeed;

#endif