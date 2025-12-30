#include "lib/backgroundTask.h"

void
runBackgroundTasks(timer &t) {
    for ( auto it = backgroundTasks.begin(); it != backgroundTasks.end(); it++ ) {
        (*it)->run();
    }
    t.stall();
}