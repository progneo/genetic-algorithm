#include "population.h"
#include "individual.h"
#include <vector>

namespace population
{
    std::vector<std::vector<double>> generate(const int &size, const double &min, const double &max)
    {
        std::vector<std::vector<double>> population;
        for (int i = 0; i < size; i++)
        {
            population.push_back(individual::generate(min, max));
        }
        return population;
    }
} // namespace population
