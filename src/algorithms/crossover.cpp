#include "crossover.h"
#include "../tools/tools.h"

namespace crossover
{
    std::vector<double> crossover(std::vector<double> parent1, std::vector<double> parent2)
    {
        int crossoverPoint = tools::getRandomNumber(1, parent1.size() - 1);
        for (int i = crossoverPoint; i < parent1.size(); i++)
        {
            std::swap(parent1[i], parent2[i]);
        }
        return parent1;
    }
} // namespace crossover
