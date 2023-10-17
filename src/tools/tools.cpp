#include "tools.h"
#include <random>
#include <time.h>

namespace tools
{
    double getRandomNumber(const double &min, const double &max)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(min, max);
        return dis(gen);
    }
} // namespace random