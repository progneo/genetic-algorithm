#include "selection.h"
#include "fitness.h"
#include <algorithm>

namespace selection
{
    void selection(std::vector<std::vector<double>> &population)
    {
        int size = population.size();
        std::vector<std::pair<double, std::vector<double>>> fitnessScores;

        for (int i = 0; i < size; i++)
        {
            double fitness = fitness::calculateIndividual(population[i]);
            fitnessScores.push_back(std::make_pair(fitness, population[i]));
        }

        std::sort(fitnessScores.begin(), fitnessScores.end());

        for (int i = 0; i < size; i++)
        {
            population[i] = fitnessScores[i].second;
        }
    }
} // namespace selection
