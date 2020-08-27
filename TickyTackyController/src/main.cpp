/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       19956                                                     */
/*    Created:      Sun Sep 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h" //****Note that this currently is just a copy of the previous years code

using namespace vex;
motor leftFrontMotor(PORT19, gearSetting::ratio18_1, true);
motor rightFrontMotor(PORT20, gearSetting::ratio18_1, true);

motor leftBackMotor(PORT10, gearSetting::ratio18_1, true);
motor rightBackMotor(PORT9, gearSetting::ratio18_1, true);

motor intakeLeft(PORT11, gearSetting::ratio18_1, true);
motor intakeRight(PORT1, gearSetting::ratio18_1, true);

motor lift(PORT18, gearSetting::ratio18_1, true);


vision frontView(vex::PORT1);
bool canSpin = false;
bool isControlled = true;

controller Controller1;
// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
  int count = 1;
        //comment kjhsdhjfsdsdfhjksdfjkhsdf

  while(count == 1)
  {
    int32_t intakeSpeed = 50;

    while(isControlled == true) 
    { //pure minus maybe?
            rightFrontMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, vex::velocityUnits::pct);
            leftFrontMotor.spin(vex::directionType::rev, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, vex::velocityUnits::pct);
            rightBackMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, vex::velocityUnits::pct);
            leftBackMotor.spin(vex::directionType::rev, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, vex::velocityUnits::pct);
            if(((Controller1.Axis2.value() - Controller1.Axis1.value()) / 2) != 0)
            {
              lift.spin(vex::directionType::fwd, (Controller1.Axis2.value() - Controller1.Axis1.value()) / 3.2, vex::velocityUnits::pct);
            }
            else
            {
              lift.stop(brakeType::brake);
            }

            if(Controller1.ButtonA.pressing() == true)
            {
              intakeLeft.spin(vex::directionType::fwd, (intakeSpeed), vex::velocityUnits::pct);
              intakeRight.spin(vex::directionType::rev, (intakeSpeed), vex::velocityUnits::pct);
            }
            else if(Controller1.ButtonB.pressing() == true)
            { 
              intakeLeft.spin(vex::directionType::rev, (intakeSpeed), vex::velocityUnits::pct);
              intakeRight.spin(vex::directionType::fwd, (intakeSpeed), vex::velocityUnits::pct);
            }

            else 
            {
              intakeLeft.spin(vex::directionType::fwd, (0), vex::velocityUnits::pct);
              intakeRight.spin(vex::directionType::rev, (0), vex::velocityUnits::pct);

              intakeLeft.stop(brakeType::brake);
              intakeRight.stop(brakeType::brake);
            }
    }
}
   
    
}
