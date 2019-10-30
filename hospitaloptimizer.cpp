//
// Created by Joshua2018 on 2019/10/29.
//

#include <iostream>

#include "hospitaloptimizer.h"

HospitalOptimizer::HospitalOptimizer(const std::vector<Village>& villages, std::vector<std::vector<unsigned int>> directDistances, unsigned int budget, unsigned int coverageTime, unsigned int satisfactionTime) {
    this -> villages = villages;
    total_villages = villages.size();
    ComputeMinimumDistances(directDistances);
    this -> budget = budget;
    coverage_time = coverageTime;
    satisfaction_time = satisfactionTime;
    max_answer = 0;
    for (unsigned int villageIndex = 0; villageIndex < total_villages; ++villageIndex) {
        this -> villages[villageIndex].SetCoveredVillages(GetCoveredVillages(villageIndex));
        this -> villages[villageIndex].SetSatisfiedVillages(GetSatisfiedVillages(villageIndex));
    }
}

void HospitalOptimizer::PrintMinimumDistances() {
    for (const std::vector<unsigned int>& row : minimum_distances) {
        for (unsigned int minimum_distance : row) {
            if (minimum_distance == 100000000) {
                std::cout << -1;
            } else {
                std::cout << minimum_distance;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

unsigned int HospitalOptimizer::GetCoverageTime() {
    return coverage_time;
}

unsigned int HospitalOptimizer::GetMaxAnswer() {
    return max_answer;
}

std::set<unsigned int> HospitalOptimizer::GetOptimizedHospitals() {
    ComputeSolution(0, std::set<unsigned int>(), budget, std::set<unsigned int>(), std::set<unsigned int>(), 0);
    return villages_with_hospital;
}

std::vector<Village> HospitalOptimizer::GetVillages() {
    return villages;
}

void HospitalOptimizer::ComputeSolution(unsigned int villageIndex,
                                        std::set<unsigned int> villagesWithHospital,
                                        unsigned int budgetLeft,
                                        std::set<unsigned int> coveredVillages,
                                        std::set<unsigned int> satisfiedVillages,
                                        int currentAnswer) {
    if (villageIndex >= total_villages) {
        if (coveredVillages.size() == total_villages && currentAnswer > max_answer) {
            std::cout << currentAnswer << " " << max_answer << std::endl;
            max_answer = currentAnswer;
            villages_with_hospital = villagesWithHospital;
        }
        return;
    }

    ComputeSolution(villageIndex + 1, villagesWithHospital, budgetLeft, coveredVillages, satisfiedVillages, currentAnswer);

    villagesWithHospital.insert(villageIndex);
    if (budgetLeft < villages[villageIndex].GetConstructionCost()) {
        if (coveredVillages.size() == total_villages && currentAnswer > max_answer) {
            std::cout << currentAnswer << " " << max_answer << std::endl;
            max_answer = currentAnswer;
            villages_with_hospital = villagesWithHospital;
        }
        return;
    } else {
        budgetLeft -= villages[villageIndex].GetConstructionCost();
    }
    for (unsigned int coveredVillage : villages[villageIndex].GetCoveredVillages()) {
        coveredVillages.insert(coveredVillage);
    }
    for (unsigned int satisfiedVillage : villages[villageIndex].GetSatisfiedVillages()) {
        if (!satisfiedVillages.count(satisfiedVillage)) {
            satisfiedVillages.insert(satisfiedVillage);
            currentAnswer += villages[satisfiedVillage].GetPopulation();
        }
    }
    ComputeSolution(villageIndex + 1, villagesWithHospital, budgetLeft, coveredVillages, satisfiedVillages, currentAnswer);
}

void HospitalOptimizer::ComputeMinimumDistances(std::vector<std::vector<unsigned int>> &directDistances) {
    minimum_distances = directDistances;

    for (unsigned int k = 0; k < total_villages; ++k) {
        for (unsigned int i = 0; i < total_villages; ++i) {
            for (unsigned int j = 0; j < total_villages; ++j) {
                if (minimum_distances[i][k] + minimum_distances[k][j] < minimum_distances[i][j]) {
                    minimum_distances[i][j] = minimum_distances[i][k] + minimum_distances[k][j];
                }
            }
        }
    }
}

std::set<unsigned int> HospitalOptimizer::GetCoveredVillages(unsigned int villageIndex) {
    std::set<unsigned int> coveredVillages = std::set<unsigned int>();

    for (unsigned int otherVillageIndex = 0; otherVillageIndex < total_villages; ++otherVillageIndex) {
        if (minimum_distances[villageIndex][otherVillageIndex] <= coverage_time) {
            coveredVillages.insert(otherVillageIndex);
        }
    }

    return coveredVillages;
}

std::set<unsigned int> HospitalOptimizer::GetSatisfiedVillages(unsigned int villageIndex) {
    std::set<unsigned int> satisfiedVillages = std::set<unsigned int>();

    for (unsigned int otherVillageIndex = 0; otherVillageIndex < total_villages; ++otherVillageIndex) {
        if (minimum_distances[villageIndex][otherVillageIndex] <= satisfaction_time) {
            satisfiedVillages.insert(otherVillageIndex);
        }
    }

    return satisfiedVillages;
}

