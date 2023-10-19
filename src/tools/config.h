#ifndef GA_TOOLS_CONFIG_H_
#define GA_TOOLS_CONFIG_H_

namespace config
{
    double targetFunction(const double &x);
    extern double minY;
    extern double maxY;
    extern double targetDistance;
    extern int populationSize;
    extern int maxIterations;
} // namespace config

#endif // GA_TOOLS_CONFIG_H_