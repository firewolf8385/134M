/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Colby Krawczyk                                            */
/*    Created:      Sun Feb 02 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "Sensors/Encoder.h"
#include "vex.h"

using namespace vex;

// Register Devices
brain Brain;
competition Competition;
controller Controller1;
inertial Inertial(PORT7);
motor DriveC(PORT9);
motor DriveL(PORT11);
motor DriveR(PORT20, true);
motor IntakeL(PORT13);
motor IntakeR(PORT18, true);
motor LiftL(PORT12, true);
motor LiftR(PORT17);
motor Tilter(PORT14);

// Runs important functions before the start of the program.
void pre_auton(void)
{
  // Gives time to position the robot.
  task::sleep(2000);

  // Reset motor encoders.
  Encoder::reset(DriveC);
  Encoder::reset(DriveL);
  Encoder::reset(DriveR);
  Encoder::reset(IntakeL);
  Encoder::reset(IntakeR);
  Encoder::reset(LiftL);
  Encoder::reset(LiftR);
  Encoder::reset(Tilter);

  // Calibrate Inertial Sensor
  Inertial.calibrate();
}

// Robot moves without driver input.
void autonomous(void)
{

}

// Robot moves with driver input.
void usercontrol(void)
{
  while(true)
  {
    // Prevents the program from hogging all system resources.
    task::sleep(20);
  }
}

int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevents main from exiting.
  while (true)
  {
    wait(100, msec);
  }
}
