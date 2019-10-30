//
// Created by Joshua2018 on 2019/10/29.
//

#ifndef NTU_106_1_MIDTERM_CLION__HOSPITALOPTIMIZER_H_
#define NTU_106_1_MIDTERM_CLION__HOSPITALOPTIMIZER_H_

#include <vector>

#include "village.h"

class HospitalOptimizer {
public:
    HospitalOptimizer(const std::vector<Village>& villages, std::vector<std::vector<unsigned int>> directDistances, unsigned int budget, unsigned int coverageTime, unsigned int satisfactionTime);
    void PrintMinimumDistances();
    unsigned int GetCoverageTime();
    unsigned int GetMaxAnswer();
    std::set<unsigned int> GetOptimizedHospitals();
    std::vector<Village> GetVillages();
private:
    void ComputeSolution(unsigned int villageIndex,
        std::set<unsigned int> villagesWithHospital,
        unsigned int budgetLeft,
        std::set<unsigned int> coveredVillages,
        std::set<unsigned int> satisfiedVillages,
        int currentAnswer);
    void ComputeMinimumDistances(std::vector<std::vector<unsigned int>> &directDistances);
    std::set<unsigned int> GetCoveredVillages(unsigned int villageIndex);
    std::set<unsigned int> GetSatisfiedVillages(unsigned int villageIndex);
    std::set<unsigned int> villages_with_hospital;
    std::vector<Village> villages;
    std::vector<std::vector<unsigned int>> minimum_distances;
    unsigned int total_villages;
    unsigned int budget;
    unsigned int coverage_time;
    unsigned int satisfaction_time;
    int max_answer;
};

#endif //NTU_106_1_MIDTERM_CLION__HOSPITALOPTIMIZER_H_
