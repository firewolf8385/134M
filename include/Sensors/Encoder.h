#ifndef _ENCODER_
#define _ENCODER_

#include "vex.h"

namespace Encoder
{
  double getPosition(vex::motor m);
  void reset(vex::motor m);
}

#endif