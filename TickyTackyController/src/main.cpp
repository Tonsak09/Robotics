/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       19956                                                     */
/*    Created:      Sun Sep 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h" //****Note that this currently is just a copy of the previous years code
//fucker
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

float speed = 0.43f;

float intakeSpeed2 = 25.1;;

int main() {
  int count = 1;
        //comment kjhsdhjfsdsdfhjksdfjkhsdf

  while(count == 1)
  {
    int32_t intakeSpeed = 50;

    while(isControlled == true) 
    { //pure minus maybe?
      /*
      float unitCircle[2];
      unitCircle[0] = Controller1.Axis4.value() / 127;
      unitCircle[1] = Controller1.Axis3.value() / 127;
      */
      
        rightFrontMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value()* 0.8f) * speed, vex::velocityUnits::pct);
        leftFrontMotor.spin(vex::directionType::rev, (Controller1.Axis3.value() + Controller1.Axis4.value()* 0.8f) * speed, vex::velocityUnits::pct);
        rightBackMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value() * 0.8f) * speed, vex::velocityUnits::pct);
        leftBackMotor.spin(vex::directionType::rev, (Controller1.Axis3.value() + Controller1.Axis4.value()* 0.8f) * speed, vex::velocityUnits::pct);
            
        if(Controller1.ButtonR1.pressing() == true)
            {
              liftRight.spin(vex::directionType::fwd, (intakeSpeed2), vex::velocityUnits::pct);
              liftLeft.spin(vex::directionType::rev, (intakeSpeed2), vex::velocityUnits::pct);
            }
            else if(Controller1.ButtonR2.pressing() == true)
            {
              liftRight.spin(vex::directionType::fwd, (-intakeSpeed2), vex::velocityUnits::pct);
              liftLeft.spin(vex::directionType::rev, (-intakeSpeed2), vex::velocityUnits::pct);
            }
            else if(Controller1.ButtonX.pressing() == true)
            { 
              intakeLeft.spin(vex::directionType::fwd, (intakeSpeed2) * 2, vex::velocityUnits::pct);
              intakeRight.spin(vex::directionType::rev, (intakeSpeed2)* 2, vex::velocityUnits::pct);  
            }
            else if(Controller1.ButtonB.pressing() == true)
            { 
              intakeLeft.spin(vex::directionType::fwd, (-intakeSpeed2)* 2, vex::velocityUnits::pct);
              intakeRight.spin(vex::directionType::rev, (-intakeSpeed2)* 2, vex::velocityUnits::pct);  
            }
            else
            {
              intakeLeft.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
              intakeRight.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);  

              liftRight.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
              liftLeft.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);

              liftRight.stop(brakeType::hold);
              liftLeft.stop(brakeType::hold);
            }
      
    }
    /*if(Controller1.ButtonA.pressing() == true)
            {
              liftRight.spin(vex::directionType::fwd, (intakeSpeed2), vex::velocityUnits::pct);
              liftLeft.spin(vex::directionType::fwd, (intakeSpeed2), vex::velocityUnits::pct);
            }
            else if(Controller1.ButtonB.pressing() == true)
            { 
              intakeLeft.spin(vex::directionType::rev, (intakeSpeed2), vex::velocityUnits::pct);
              intakeRight.spin(vex::directionType::rev, (intakeSpeed2), vex::velocityUnits::pct);
            }*/
  }  
}
