#include "ga/population.h"
#include "ga/crossover.h"
#include "ga/mutation.h"
#include "ga/selection.h"
#include "ga/fitness.h"
#include <cmath>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <matplot/matplot.h>

std::vector<double> startAlgorithm()
{
    int populationSize = 20;
    double min = 0;
    double max = 100;
    int maxIterations = 1000;
    double targetDistance = 0.5;

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

        for (int i = 10; i < population.size(); i += 2)
        {
            population[i] = crossover::crossover(population[i - 9], population[i - 9]);
            population[i + 1] = crossover::crossover(population[i - 8], population[i - 10]);
        }

        for (int i = 0; i < population.size(); i += 2)
        {
            mutation::mutate(population[i]);
            mutation::mutate(population[i + 1]);
        }

        iteration++;
    }

    std::cout << "Best Individual: ";
    for (double value : bestIndividual)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Iteration: " << iteration << std::endl;
    std::cout << "Distance: " << bestDistance << std::endl;

    return bestIndividual;
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<double> individual = startAlgorithm();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "Time: " << ms_double.count() << "ms\n";

    using namespace matplot;

    std::vector<double> x = linspace(0, 10, 100);
    plot(x, individual)->color({0.f, 0.7f, 0.9f});
    title("Best Individual");
    xlabel("x");
    ylabel("x * x");

    show();
    return 0;
}