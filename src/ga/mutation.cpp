#include "mutation.h"
#include "fitness.h"
#include "../tools/tools.h"

namespace mutation
{
    void mutate(std::vector<double> &individual)
    {
        int lenght = individual.size();

        int worstPoint = 0;
        double worstFitness = 0;
        double currentFitness;

        for (int i = 0; i < lenght; i++)
        {
            currentFitness = fitness::calculatePoint(i * 0.1, individual[i]);
            if (currentFitness > worstFitness)
            {
                worstPoint = i;
                worstFitness = currentFitness;
            }
        }

        double mutatedValue;
        double mutatedFitness = INT16_MAX;

        while (mutatedFitness >= worstFitness)
        {
            mutatedValue = tools::getRandomNumber(0, 100);
            mutatedFitness = fitness::calculatePoint(worstPoint * 0.1, mutatedValue);
        }
        
        individual[worstPoint] = mutatedValue;
    }
} // namespace mutation
