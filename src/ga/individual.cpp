#include "individual.h"
#include "../tools/tools.h"
#include <vector>
#include <math.h>

namespace individual
{
    std::vector<double> generate(const double &min, const double &max)
    {
        std::vector<double> individual;
        for (double x = 0; x <= 10; x += 0.1)
        {
            individual.push_back(tools::getRandomNumber(min, max));
        }
        return individual;
    }
} // namespace individual
