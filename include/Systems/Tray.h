#ifndef _TRAY_
#define _TRAY_

#include "Devices.h"

namespace Tray
{
  extern double position;
  
  void control();
  void in();
  void out();
  void setMoving(bool m);
  void override();
  void startMoving();
  void stopMoving();
}

#endif