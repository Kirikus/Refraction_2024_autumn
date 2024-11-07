#include "gost_model.h"

template <class PressureModel, class TemperatureModel>
double GOSTModel<PressureModel, TemperatureModel>::pho_w(double height) {
    double maxWaterDensity = 12.8;
    double relativeHumidity = 0.6;
    const double initialWaterDensity = maxWaterDensity * relativeHumidity;
    const double lowSlope = 0.2523 / 1000;
    const double heightThreshold1 = 2000;
    const double heightThreshold2 = 8000;
    const double waterDensityThreshold1 = (1 - lowSlope * heightThreshold1);
    const double midSlope = 1861;
    const double waterDensityThreshold2 = waterDensityThreshold1 * std::exp(-
                                          (heightThreshold2 - 2000) / midSlope);
    const double highSlope = 1158;

    if (height < heightThreshold1)
        return initialWaterDensity * (1 - lowSlope * height);
    else if (height < heightThreshold2)
        return initialWaterDensity * waterDensityThreshold1 * std::exp(-
                (height - heightThreshold1) / midSlope);
    return initialWaterDensity * waterDensityThreshold2 * std::exp(-
            (height - heightThreshold2) / highSlope);
}

template <class PressureModel, class TemperatureModel>
double GOSTModel<PressureModel, TemperatureModel>::N(double h) {
    double T = Temp_M.f(h);
    double P = Press_M.f(h);
    double e = T * rho_w(h) / 216.68;
    return 77.6 / T * (P + 4810 * e / T);
}

template class GOSTModel<Linear, Linear>;
