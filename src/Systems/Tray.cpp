#include "Devices.h"
#include "Systems/Remote.h"
#include "Systems/Tray.h"

using namespace vex;

namespace Tray
{
  // Variables
  double kP = 0.15;
  double kD = 0.15;
  double lastError = 0;
  bool moving = false;
  bool overrideTray = false;
  double position = 0.0;

  /**
   * Control the tray.
   */
  void control()
  {
    // Set up events.
    Controller1.ButtonUp.pressed(startMoving);
    Controller1.ButtonUp.released(stopMoving);
    Controller1.ButtonDown.pressed(startMoving);
    Controller1.ButtonDown.released(stopMoving);
    Controller1.ButtonR1.pressed(startMoving);
    Controller1.ButtonR1.released(stopMoving);
    Controller1.ButtonR2.pressed(startMoving);
    Controller1.ButtonR2.released(stopMoving);
    Controller1.ButtonX.pressed(override);

    // Move tray up.
    if(Controller1.ButtonUp.pressing())
    {
      // Add the lift position to the target.
      double target = 915 + (LiftR.position(deg) * 1.23);
      double error = target - Tilter.position(deg);

      // Calculates the correct speed.
      double speed = (error * kP) + (lastError * kD);

      // Moves the tray.
      if(overrideTray)
      {
        Tilter.spin(directionType::fwd, 25, velocityUnits::pct);
      }
      else
      {
        Tilter.spin(directionType::fwd, speed, velocityUnits::pct);
      }
    }

    // Move tray down.
    else if(Controller1.ButtonDown.pressing())
    {
      Tilter.spin(directionType::rev, 50, velocityUnits::pct);
    }

    // Stop moving tray.
    else if(moving == false)
    {
      Tilter.stop(hold);
    }

  }

  /**
   * Toggles the tray override
   */
  void override()
  {
    if(overrideTray)
    {
      overrideTray = false;
    }
    else
    {
      overrideTray = true;
    }

    Remote::info();
  }

  /**
   * Tells the robot that the tray is moving.
   */
  void startMoving()
  {
    moving = true;
    Brain.Screen.clearLine(1,color::black);
    Brain.Screen.setCursor(1,0);
    Brain.Screen.print("Moving");
  }

  /**
   * Tells the robot the tray is not moving.
   */
  void stopMoving()
  {
    if(moving)
    {
      moving = false;
      Brain.Screen.clearLine(1,color::black);
      Brain.Screen.setCursor(1,0);
      Brain.Screen.print("Not Moving");
      position = Tilter.position(deg) - LiftR.position(deg);
    }
  }
}