#include "Systems/Remote.h"

namespace Remote
{
  /**
   * Recieve Axis 1 position.
   * @return Position.
   */
  float axis1()
  {
    return Controller1.Axis1.position(vex::percentUnits::pct);
  }

  /**
   * Recieve Axis 2 position.
   * @return Position.
   */
  float axis2()
  {
    return Controller1.Axis2.position(vex::percentUnits::pct);
  }

  /**
   * Recieve Axis 3 position.
   * @return Position.
   */
  float axis3()
  {
    return Controller1.Axis3.position(vex::percentUnits::pct);
  }

  /**
   * Recieve Axis 4 position.
   * @return Position.
   */

  float axis4()
  {
    return Controller1.Axis4.position(vex::percentUnits::pct);
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