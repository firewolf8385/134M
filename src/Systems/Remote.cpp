#include "Systems/Remote.h"

namespace Remote
{
  /**
   * Recieve Axis 1 position.
   * @return Position.
   */
  float axis1()
  {
    float val = Controller1.Axis1.position(vex::percentUnits::pct);

    if(val <= 5 && val >= -5)
    {
      val = 0;
    }

    return val;
  }

  /**
   * Recieve Axis 2 position.
   * @return Position.
   */
  float axis2()
  {
    float val = Controller1.Axis2.position(vex::percentUnits::pct);

    if(val <= 5 && val >= -5)
    {
      val = 0;
    }

    return val;
  }

  /**
   * Recieve Axis 3 position.
   * @return Position.
   */
  float axis3()
  {
    float val = Controller1.Axis3.position(vex::percentUnits::pct);

    if(val <= 5 && val >= -5)
    {
      val = 0;
    }

    return val;
  }

  /**
   * Recieve Axis 4 position.
   * @return Position.
   */

  float axis4()
  {
    float val = Controller1.Axis4.position(vex::percentUnits::pct);

    if(val <= 5 && val >= -5)
    {
      val = 0;
    }

    return val;
  }

  /**
   * Cause the controller to vibrate the info pattern.
   */
  void info()
  {
    Controller1.rumble(".");
  }

  /**
   * Cause the controller to vibrate the error pattern.
   */
  void error()
  {
    Controller1.rumble("-");
  }

  /**
   * Cause the controller to vibrare the warn pattern.
   */
  void warn()
  {
    Controller1.rumble(". .");
  }
}