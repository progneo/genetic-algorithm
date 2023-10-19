#include "population.h"
#include "crossover.h"
#include "mutation.h"
#include "selection.h"
#include "fitness.h"
#include <iostream>
#include <vector>
#include <cmath>

namespace ga
{
    std::vector<double> startAlgorithm(const int &populationSize, const double &min, const double &max, const int &maxIterations, const double &targetDistance)
    {
        std::vector<std::vector<double>> population = population::generate(populationSize, min, max);

        int iteration = 0;
        double bestDistance = std::numeric_limits<double>::max();
        std::vector<double> bestIndividual;

        while (iteration < maxIterations && bestDistance > targetDistance)
        {
            selection::selection(population);

            double distance = fitness::calculateIndividual(population[0]);

            if (distance < bestDistance)
            {
                bestDistance = distance;
                bestIndividual = population[0];
            }

            for (int i = 10; i < populationSize; i += 2)
            {
                population[i] = crossover::crossover(population[i - 9], population[i - 10]);
                population[i + 1] = crossover::crossover(population[i - 10], population[i - 9]);
            }

            for (int i = 0; i < populationSize; i += 1)
            {
                mutation::mutate(population[i]);
            }

            iteration++;
        }

        std::cout << "Iteration: " << iteration << std::endl;
        std::cout << "Distance: " << bestDistance << std::endl;

        return bestIndividual;
    }
} // namespace ga