#include "fitness.h"
#include "../tools/config.h"
#include <math.h>
#include <vector>

namespace fitness
{
    double calculateIndividual(const std::vector<double> &individual)
    {
        double fitness = 0.0;

        int length = individual.size();
        for (int i = 0; i < length; i++)
        {
            double x = i * 0.1;
            fitness += std::abs(config::targetFunction(x) - individual[i]);
        }

        return fitness;
    }
    double calculatePoint(const double &x, const double &point)
    {
        return std::abs(config::targetFunction(x) - point);
    }
} // namespace fitness
