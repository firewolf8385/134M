#include "Devices.h"
#include "Systems/Rollers.h"
#include "Systems/Lift.h"
#include "Systems/Remote.h"

using namespace vex;

namespace Rollers
{
  bool slowOuttake = true;

  /**
   * Control the rollers.
   */
  void control()
  {
    // Registers event.
    Controller1.ButtonY.pressed(outtakeSpeed);

    // Moves Rollers
    if(Controller1.ButtonL1.pressing())
    {
      int speed = 50;

      if(slowOuttake)
      {
        speed = 25;
      }

      // Outtake
      IntakeR.spin(directionType::fwd, speed, velocityUnits::pct);
      IntakeL.spin(directionType::fwd, speed, velocityUnits::pct);
    }
    else if(Controller1.ButtonL2.pressing())
    {
      // Intake
      IntakeR.spin(directionType::rev, 95, velocityUnits::pct);
      IntakeL.spin(directionType::rev, 95, velocityUnits::pct);
    }
    else
    {
      // Holds the claw's position.
      // This helps keep the cubes in the claw.
      IntakeR.setBrake(hold);
      IntakeR.stop();
      IntakeL.setBrake(hold);
      IntakeL.stop();
    }
  }

  /**
   * Toggles the roller outtake speed. 
   */
  void outtakeSpeed()
  {
    if(slowOuttake)
    {
      slowOuttake = false;
    }
    else
    {
      slowOuttake = true;
    }

    Remote::info();
  }

}