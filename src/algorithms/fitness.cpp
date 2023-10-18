#include "fitness.h"
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
            fitness += std::abs(targetFunction(x) - individual[i]);
        }

        return fitness;
    }
    double calculatePoint(const double &x, const double &point)
    {
        return std::abs(targetFunction(x) - point);
    }
    double targetFunction(const double &x)
    {
        return x * x;
    }
} // namespace fitness
