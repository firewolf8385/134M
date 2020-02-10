#include "Systems/Drive.h"
#include "Systems/Remote.h"
#include "Sensors/Encoder.h"

using namespace vex;

namespace Drive
{
  bool locked = false;
  double velocity = 0;

  /**
   * Set the drive motors to coast.
   */
  void coast()
  {
      DriveL.setBrake(brakeType::coast);
      DriveR.setBrake(brakeType::coast);
      DriveC.setBrake(brakeType::coast);
  }

  /**
   * Control the drive train.
   */
  void control()
  {
    // Set up events.
    Controller1.ButtonA.pressed(lock);

    // Set the speed of each drive motor.
    int center = Controller1.Axis2.position();
    int left = Controller1.Axis2.position() + Controller1.Axis4.position();
    int right = Controller1.Axis2.position() - Controller1.Axis4.position();

    // Moves the drive motors.
    DriveC.spin(directionType::fwd, center, velocityUnits::pct);
    DriveL.spin(directionType::fwd, left, velocityUnits::pct);
    DriveR.spin(directionType::fwd, right, velocityUnits::pct);
  }

  /**
   * Causes the drive train to move forwards.
   * Uses a pid for velocity.
   * @param target Target (degrees).
   */
  void forward(double target)
  {
    // Reset encoder values.
    Encoder::reset(DriveC);
    Encoder::reset(DriveL);
    Encoder::reset(DriveR);

    // Initializes variables.
    double average = 0;
    double ErrorC = 0;
    double ErrorL = 0;
    double ErrorR = 0;
    double velocityC = 0;
    double velocityL = 0;
    double velocityR = 0;

    // Constants (Values Untested - Subject to change.)
    double pGain = 1;
    double dGain = 0.2;

    while(average < target)
    {
      // Updates position of the motors.
      double valueC = Encoder::getPosition(DriveC);
      double valueL = Encoder::getPosition(DriveL);
      double valueR = Encoder::getPosition(DriveR);

      // Calculate Average
      average = (valueC + valueL + valueR) / 3;

      // Updates errors
      double lastErrorC = ErrorC;
      double lastErrorL = ErrorL;
      double lastErrorR = ErrorR;
      ErrorC = target - valueC;
      ErrorL = target - valueL;
      ErrorR = target - valueR;

      // Calculate Derrivitives
      

      // Set velocities
      velocityC = (ErrorC * pGain);
      velocityL = (ErrorL * pGain);
      velocityR = (ErrorR * pGain);

      // Moves motors
      DriveC.spin(directionType::fwd, velocityC, velocityUnits::pct);
      DriveL.spin(directionType::fwd, velocityL, velocityUnits::pct);
      DriveR.spin(directionType::fwd, velocityR, velocityUnits::pct);
    }
  }

  /**
   * Set the drive motors to hold.
   */
  void hold()
  {
    DriveL.setBrake(brakeType::hold);
    DriveR.setBrake(brakeType::hold);
    DriveC.setBrake(brakeType::hold);
  }

  /**
   * An event for locking the drive.
   * More consistant than checking Button#pressing().
   */
  void lock()
  {
    if(locked)
    {
      coast();
      locked = false;
    }
    else
    {
      hold();
      locked = true;
    }

    Remote::info();
  }

  void left()
  {

  }

  void reverse()
  {

  }

  void right()
  {

  }

  void setVelocity(double v)
  {
    velocity = v;
  }

}
