#ifndef GA_GA_FITNESS_H_
#define GA_GA_FITNESS_H_
#include <vector>

namespace fitness
{
    double calculateIndividual(const std::vector<double> &individual);
    double calculatePoint(const double &x, const double &point);
    double targetFunction(const double &x);
} // namespace fitness

#endif // GA_GA_FITNESS_H_