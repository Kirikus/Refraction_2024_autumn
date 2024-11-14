#include "refrmodel.h"

RefrResult::RefrResult(double npsi_d, double npsi_g, double nd): psi_d{npsi_d}, psi_g{npsi_g}, d{nd} {}

double RefractionModel::get_Re() const
{
    return R_e;
}
