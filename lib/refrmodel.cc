#include "refrmodel.h"


RefrResult::RefrResult() {}
RefrResult::RefrResult(double npsi_d, double npsi_g, double nd) : psi_d{npsi_d}, psi_g{npsi_g}, d{nd} {}

InvRefrResult::InvRefrResult() {}
InvRefrResult::InvRefrResult(double nh_s, double nd) : h_s{nh_s}, d{nd} {}


double RefractionModel::get_Re() const { return R_e; }

InvRefrResult RefractionModel::reverse(double h_a, double psi_d, double R)
{
    double s_begin = h_a-R,
           s_end   = h_a+R,
           nh_s;
    RefrResult answer;

    // Using binary search
    do {
        nh_s = (s_begin+s_end)/2;
        answer = this->calculate(h_a, nh_s, R);

        if (psi_d > answer.psi_d)
            s_end = nh_s;
        else
            s_begin = nh_s;
    } while (std::abs(answer.psi_d - psi_d) > 1e-6);

    return InvRefrResult(nh_s, answer.d);
}
