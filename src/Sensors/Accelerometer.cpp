#include "Devices.h"
#include "Sensors/Accelerometer.h"

using namespace vex;

namespace Accelerometer
{
  /**
   * Get the sensor's x acceleration.
   * @return x acceleration.
   */
  double accelerationX()
  {
    return Inertial.acceleration(xaxis);
  }

  /**
   * Get the sensor's y acceleration.
   * @return y acceleration.
   */
  double accelerationY()
  {
    return Inertial.acceleration(yaxis);
  }

  /**
   * Get the sensor's z acceleration.
   * @return z acceleration.
   */
  double accelerationZ()
  {
    return Inertial.acceleration(zaxis);
  }
}