#include "lib/vexio.h"

void 
deadZone( ControllerAxes* axes, int lthresh, int rthresh ) {

    if ( axes->lx * axes->lx + axes->ly * axes->ly < lthresh * lthresh) {
        axes->lx = axes->ly = 0;
    }
    if (axes->rx * axes->rx + axes->ry * axes->ry < rthresh * rthresh ) {
        axes->rx = axes->ry = 0;
    }
}