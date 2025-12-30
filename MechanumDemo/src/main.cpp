/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       tatew                                                     */
/*    Created:      12/30/2025, 12:57:43 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "robot-config.h"
#include "lib/robot-middleware.h"
#include "lib/mechanum.h"

using namespace vex;
// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
vex::controller Controller1(primary);
vex::inertial Gyro(PORT17);

vex::motor Motor8(PORT8);
vex::motor Motor9(PORT9, true);
vex::motor Motor11(PORT11);
vex::motor Motor20(PORT20, true);

int main() {

    Brain.Screen.printAt( 10, 50, "Calibrating" );
    Gyro.calibrate(3);
   
    while(1) {
        
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
