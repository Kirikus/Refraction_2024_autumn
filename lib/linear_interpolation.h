#pragma once
#include <vector>

//TBD

class Linear : public RtoRMap {
    public:
        Linear(const std::vector<std::pair<double, double>>& map_table) : RtoRMap(map_table) {}
        virtual double f(double x) override;
};
