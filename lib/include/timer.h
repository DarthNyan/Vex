#ifndef __TIMER_H
#define __TIMER_H

#include "robot-middleware.h"

enum TickTime { FAST_TICK = 1, MOTOR_REFRESH = 20, RADAR_REFRESH = 50 };

class timer {
public:
    timer(TickTime _tick) {
        tick = _tick;
        reset();
    }
    void reset() { start = cpuTime(); wait = start; }
    int time() { return cpuTime() - start; }
    void stall() { wait += tick; while (cpuTime() < wait) {} }
private:
    int start;
    int wait;
    TickTime tick;
};

timer FAST_TIMER(FAST_TICK);
timer MOTOR_TIMER(MOTOR_REFRESH);
timer RADAR_TIMER(RADAR_REFRESH);

#endif