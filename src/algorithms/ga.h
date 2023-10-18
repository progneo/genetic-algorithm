#ifndef GA_ALGORITHMS_GA_H_
#define GA_ALGORITHMS_GA_H_
#include <vector>

namespace ga
{
    std::vector<double> startAlgorithm(const int &populationSize, const double &min, const double &max, const int &maxIterations, const double &targetDistance);
} // namespace ga

#endif // GA_ALGORITHMS_GA_H_