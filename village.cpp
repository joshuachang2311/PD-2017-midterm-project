//
// Created by Joshua2018 on 2019/10/29.
//
#include <set>

#include "village.h"

Village::Village() {
    population = 0;
    construction_cost = 0;
    has_hospital = false;
    is_covered = false;
    is_satisfied = false;
    covered_villages.clear();
    satisfied_villages.clear();
}

Village::Village(unsigned int population, unsigned int constructionCost) {
    this -> population = population;
    construction_cost = constructionCost;
    has_hospital = false;
    is_covered = false;
    is_satisfied = false;
    covered_villages.clear();
    satisfied_villages.clear();
}

unsigned int Village::GetPopulation() {
    return population;
}

unsigned int Village::GetConstructionCost() {
    return construction_cost;
}

bool Village::HasHospital() {
    return has_hospital;
}

bool Village::IsCovered() {
    return is_covered;
}

bool Village::IsSatisfied() {
    return is_satisfied;
}

void Village::SetCoveredVillages(std::set<unsigned int> coveredVillages) {
    covered_villages = coveredVillages;
}

void Village::SetSatisfiedVillages(std::set<unsigned int> satisfiedVillages) {
    satisfied_villages = satisfiedVillages;
}

std::set<unsigned int> Village::GetCoveredVillages() {
    return covered_villages;
}

std::set<unsigned int> Village::GetSatisfiedVillages() {
    return satisfied_villages;
}
