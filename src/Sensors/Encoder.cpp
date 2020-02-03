#include "Devices.h"
#include "Sensors/Encoder.h"

using namespace vex;

namespace Encoder
{
	/**
	 * Get the position of a motor.
	 * @param m Motor.
	 * @return Position.
	 */
	double getPosition(motor m)
	{
		return m.position(degrees);
	}
	
  /**
   * Reset a motor's encoder values.
   * @param m Motor.
   */
	void reset(motor m)
	{
    m.resetRotation();
    m.resetPosition();
	}

}