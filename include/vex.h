#ifndef VEX_H
#define VEX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "helpers.h"

// UI Elements
#include "ui/button.hpp"
#include "ui/paintable.hpp"
#include "ui/text.hpp"
#include "ui/canvas.hpp"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

#endif