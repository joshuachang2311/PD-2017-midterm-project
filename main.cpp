#include <vector>
#include <iostream>

#include "hospitaloptimizer.h"

int main(int argc, char** argv) {
    const unsigned int MAX_DISTANCE = 100000000;
    unsigned int totalVillages;
    unsigned int budget;
    unsigned int coverageTime;
    unsigned int satisfactionTime;
    std::vector<unsigned int> populations;
    std::vector<unsigned int> constructionCosts;
    std::vector<Village> villages;
    std::vector<std::vector<unsigned int>> graph;

    std::cin >> totalVillages >> budget >> coverageTime >> satisfactionTime;
    populations.resize(totalVillages);
    constructionCosts.resize(totalVillages);
    villages.resize(totalVillages);
    graph.resize(totalVillages);
    for (unsigned int villageIndex = 0; villageIndex < totalVillages; ++villageIndex) {
        graph[villageIndex].resize(totalVillages);
    }

    for (unsigned int villageIndex = 0; villageIndex < totalVillages; ++villageIndex) {
        std::cin >> populations[villageIndex];
    }
    for (unsigned int villageIndex = 0; villageIndex < totalVillages; ++villageIndex) {
        std::cin >> constructionCosts[villageIndex];
    }
    for (unsigned int villageIndex = 0; villageIndex < totalVillages; ++villageIndex) {
        villages[villageIndex] = Village(populations[villageIndex], constructionCosts[villageIndex]);
    }

    for (unsigned int villageIndex = 0; villageIndex < totalVillages; ++villageIndex) {
        graph[villageIndex][villageIndex] = 0;
        for (unsigned int otherVillageIndex = villageIndex + 1; otherVillageIndex < totalVillages; ++otherVillageIndex) {
            int bufferInt;
            std::cin >> bufferInt;

            if (bufferInt < 0) {
                graph[villageIndex][otherVillageIndex] = MAX_DISTANCE;
                graph[otherVillageIndex][villageIndex] = MAX_DISTANCE;
            } else {
                graph[villageIndex][otherVillageIndex] = bufferInt;
                graph[otherVillageIndex][villageIndex] = bufferInt;
            }
        }
    }

	HospitalOptimizer hospitalOptimizer = HospitalOptimizer(villages, graph, budget, coverageTime, satisfactionTime);
	for (unsigned int hospital : hospitalOptimizer.GetOptimizedHospitals()) {
	    std::cout << hospital + 1 << " ";
	}

	return EXIT_SUCCESS;
}