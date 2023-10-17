#ifndef GA_GA_POPULATION_H_
#define GA_GA_POPULATION_H_
#include <vector>

namespace population
{
    std::vector<std::vector<double>> generate(const int &size, const double &min, const double &max);
} // namespace population

#endif // GA_GA_POPULATION_H_