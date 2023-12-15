#ifndef VEX_H
#define VEX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>

#include "v5.h"
#include "v5_vcs.h"

#include "vex_color.h"
#include "vex_brain.h"
#include "vex_units.h"

#include "robot-config.h"
#include "helpers.h"

// UI Elements
#include "ui/paintable.hpp"
#include "ui/canvas.hpp"
#include "ui/text.hpp"
#include "ui/button.hpp"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

namespace Util {
	template<class from, class target>
	target* cast(from obj) {
		from* objPtr = &obj;
		target* targetPtr = dynamic_cast<target*>(objPtr);
		return targetPtr;
	}
}

#endif