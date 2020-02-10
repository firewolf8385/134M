#ifndef _DRIVE_
#define _DRIVE_

#include "Devices.h"

namespace Drive
{
  void coast();
  void control();
  void forward(double degrees);
  void hold();
  void left(double degrees);
  void lock();
  void reverse(double degrees);
  void right(double degrees);
  void setVelocity(double velocity);
}

#endif