#ifndef __BACKGROUND_TASK_H
#define __BACKGROUND_TASK_H

#include "timer.h"
#include <vector>

class BackgroundTask {
public:
    virtual void run();
};

std::vector<BackgroundTask*> backgroundTasks = {};

// Runs all PID loops and stalls for the given time before continuing.
void
runBackgroundTasks(timer &t);
#endif
