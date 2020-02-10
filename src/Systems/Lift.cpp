#include "Devices.h"
#include "Systems/Tray.h"
#include "Systems/Remote.h"
#include "Systems/Lift.h"

using namespace vex;

namespace Lift
{
  double position = 0;
  double lastPosition = 0;

  /**
   * Control the lift.
   */
  void control()
  {

    // Moves Lift
    if(Controller1.ButtonR1.pressing())
    {
      LiftL.spin(directionType::fwd, 95, velocityUnits::pct);
      LiftR.spin(directionType::fwd, 95, velocityUnits::pct);
      
      double target = Tray::position + LiftR.position(deg);
      double error = target - Tilter.position(deg);

      // Calculates the correct speed.
      double speed = (error * 1.2);

      // Move tray with Lift.
      Tilter.spin(fwd, speed, pct);
    }
    else if(Controller1.ButtonR2.pressing())
    {
      LiftL.spin(directionType::rev, 95, velocityUnits::pct);
      LiftR.spin(directionType::rev, 95, velocityUnits::pct);

      double target = Tray::position + LiftR.position(deg);
      double error = target + Tilter.position(deg);

      // Calculates the correct speed.
      double speed = (error * 1.2);
      Tilter.spin(reverse, speed, pct);
      }
    else
    {
      LiftL.setBrake(hold);
      LiftR.setBrake(hold);
      LiftL.stop();
      LiftR.stop();
    }
  }

}