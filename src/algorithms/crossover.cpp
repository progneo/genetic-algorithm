#include "crossover.h"
#include "../tools/tools.h"

namespace crossover
{
    std::vector<double> crossover(std::vector<double> parent1, std::vector<double> parent2)
    {
        int length = parent1.size();
        int crossoverPoint = tools::getRandomNumber(1, length - 1);
        for (int i = crossoverPoint; i < length; i++)
        {
            std::swap(parent1[i], parent2[i]);
        }
        return parent1;
    }
} // namespace crossover
