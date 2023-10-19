#include "config.h"

namespace config
{
    double targetFunction(const double &x)
    {
        return x * x;
    }
    double minY = 0;
    double maxY = 100;
    double targetDistance = 0.5;
    int populationSize = 20;
    int maxIterations = 1000;
} // namespace config
