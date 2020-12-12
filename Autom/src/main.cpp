/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       19956                                                     */
/*    Created:      Sat Dec 12 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;
motor leftFrontMotor(PORT11, gearSetting::ratio18_1, true);
motor rightFrontMotor(PORT1, gearSetting::ratio18_1, true);

motor leftBackMotor(PORT19, gearSetting::ratio18_1, true);
motor rightBackMotor(PORT12, gearSetting::ratio18_1, true);
//testing testing
motor intakeLeft(PORT15, gearSetting::ratio18_1, true);
motor intakeRight(PORT2, gearSetting::ratio18_1, true);

motor liftLeft(PORT16, gearSetting::ratio18_1, true);
motor liftRight(PORT10, gearSetting::ratio18_1, true);


vision frontView(vex::PORT1);
bool canSpin = false;
bool isControlled = true;

controller Controller1;
// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
    double speed = 1;
    rightFrontMotor.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
    leftFrontMotor.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
    rightBackMotor.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
    leftBackMotor.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);

    vex::task::sleep(5000);

    rightFrontMotor.spin(vex::directionType::fwd, -speed, vex::velocityUnits::pct);
    leftFrontMotor.spin(vex::directionType::rev, -speed, vex::velocityUnits::pct);
    rightBackMotor.spin(vex::directionType::fwd, -speed, vex::velocityUnits::pct);
    leftBackMotor.spin(vex::directionType::rev, -speed, vex::velocityUnits::pct);

    vex::task::sleep(3000);

    rightFrontMotor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    leftFrontMotor.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    rightBackMotor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    leftBackMotor.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);

}
