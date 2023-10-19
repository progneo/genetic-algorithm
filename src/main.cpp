#include "algorithms/ga.h"
#include "tools/config.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <matplot/matplot.h>

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();

    std::vector<double> individual = ga::startAlgorithm(
        config::populationSize,
        config::minY,
        config::maxY,
        config::maxIterations,
        config::targetDistance);

    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "Time: " << ms_double.count() << "ms\n";

    std::vector<double> target;
    for (double i = 0; i <= 10; i = i + 0.1)
    {
        target.push_back(config::targetFunction(i));
    }

    using namespace matplot;

    std::vector<double> x = linspace(0, 10, 101);
    
    auto p = plot(x, individual, x, target, "--");
    title("Result");
    xlabel("x");

    show();
    return 0;
}