#include "Devices.h"
#include "Sensors/Gyro.h"

namespace Gyro
{
  /**
   * Get the gyro's pitch.
   * @return Pitch.
   */
  double pitch()
  {
    return Inertial.pitch();
  }

  /**
   * Get the gyro's roll.
   * @return Roll.
   */
  double roll()
  {
    return Inertial.roll();
  }

  /**
   * Get the gyro's yaw.
   * @return yaw.
   */
  double yaw()
  {
    return Inertial.yaw();
  }
}