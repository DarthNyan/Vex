#ifndef __FOLLOW_PID_H
#define __FOLLOW_PID_H

#include "pid.h"
#include "backgroundTask.h"

/*
 * Commands a motor to follow a target given a function to get an input value, a function to spin motors,
 * and a PID controller.
 * 
 * Example instantiation (using Lambdas & arbitrary PID values)
 * FollowPid followArm(
 *     []() { return armMotor.getPosition(); },
 *     [](float x) { armMotor.spin(x); },
 *     PID(5, 0.1, -2, 10, 3)
 * );
 * 
 * To register this with the Bakcground Task Runner ( so that it'll execute in loops ), simply write
 * backgroundTasks.push_back(&followArm);
*/
typedef std::function<float()> InputFn;
typedef std::function<void(float)> OutputFn;

class FollowPID : BackgroundTask {
public:
    FollowPID(InputFn _input, OutputFn _move, PID _pid) {
        input = _input;
        move = _move;
        pid = _pid;
        target = input();
        enabled = true;
    }
    void run() { if( enabled ) move( pid.update( target - input() ) ); }
    void setTarget( float _target ) {target = _target; }
    void enable() { enabled = true; }
    void disable() {enabled = false; }
private:
    InputFn input;
    OutputFn move;
    PID pid;
    float target;
    bool enabled;
};

#endif