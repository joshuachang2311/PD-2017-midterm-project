//
// Created by Joshua2018 on 2019/10/29.
//

#ifndef NTU_106_1_MIDTERM_CLION__VILLAGE_H_
#define NTU_106_1_MIDTERM_CLION__VILLAGE_H_

#include <set>

class Village {
public:
    Village();
    Village(unsigned int population, unsigned int constructionCost);
    unsigned int GetPopulation();
    unsigned int GetConstructionCost();
    bool HasHospital();
    bool IsCovered();
    bool IsSatisfied();
    void SetCoveredVillages(std::set<unsigned int> coveredVillages);
    void SetSatisfiedVillages(std::set<unsigned int> satisfiedVillages);
    std::set<unsigned int> GetCoveredVillages();
    std::set<unsigned int> GetSatisfiedVillages();
private:
    unsigned int population;
    unsigned int construction_cost;
    bool has_hospital;
    bool is_covered;
    bool is_satisfied;
    std::set<unsigned int> covered_villages;
    std::set<unsigned int> satisfied_villages;
};

#endif //NTU_106_1_MIDTERM_CLION__VILLAGE_H_
