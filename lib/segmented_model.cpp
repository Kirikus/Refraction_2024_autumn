#include "segmented_model.h"
#include <stdexcept>

double SegmentedAtmosphere::N(double h) {
    if (hs <= h && h <= hs + 1000) {
        return Ns + (h - hs) * dN;
    }
    if (hs + 1000 <= h && h <= 9000) {
        return N1 * exp(-(h - hs - 1000) / H);
    }
    if (h > 9000) {
        return 105 * exp(-(h - 9000) / 7023);
    }
    throw std::runtime_error("Undefined refractive index");
    return 0;
}
