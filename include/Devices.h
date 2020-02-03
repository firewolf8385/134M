#ifndef _DEVICES_
#define _DEVICES_

#include "vex.h"

extern vex::competition Competition;
extern vex::brain Brain;
extern vex::controller Controller1;

// Drive Motors
extern vex::motor DriveR;
extern vex::motor DriveL;
extern vex::motor DriveC;

// Lift Motors
extern vex::motor LiftL;
extern vex::motor LiftR;

// Intake Motors
extern vex::motor IntakeL;
extern vex::motor IntakeR;

// Tilter Motor
extern vex::motor Tilter;

// Sensors
extern vex::inertial Inertial;

#endif