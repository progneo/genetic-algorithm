#ifndef GA_ALGORITHMS_FITNESS_H_
#define GA_ALGORITHMS_FITNESS_H_
#include <vector>

namespace fitness
{
    double calculateIndividual(const std::vector<double> &individual);
    double calculatePoint(const double &x, const double &point);
} // namespace fitness

#endif // GA_ALGORITHMS_FITNESS_H_