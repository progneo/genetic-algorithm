#include "algorithms/ga.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <matplot/matplot.h>

int main()
{
    int populationSize = 20;
    double min = 0;
    double max = 100;
    int maxIterations = 1000;
    double targetDistance = 0.5;

    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<double> individual = ga::startAlgorithm(populationSize, min, max, maxIterations, targetDistance);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "Time: " << ms_double.count() << "ms\n";

    using namespace matplot;

    std::vector<double> x = linspace(0, 10, 101);
    auto p = plot(x, individual);
    p->line_width(2);
    title("Best Individual");
    xlabel("x");
    ylabel("x * x");

    show();
    return 0;
}