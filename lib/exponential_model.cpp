#include "exponential_model.h"

double ExponentialAtmosphere::N(double h) {
  // Values for diaposon 0 - 15 km
  return Ns * exp(-(h - hs) / Hb);
}
