#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include <iostream>
#include <vector>
#include "district.h"
#include "elec_data.h"
using namespace std;

class Household {
    public:
    Household(District&, const string&, const string&);
    BinarySearchTree<electricityData>::BinaryNode* getElectricityData()const;
    void addElectricityData(electricityData);
    void removeElectricityData(electricityData);
    void setId();
    void setFirstName(const string&);
    void setLastName(const string&);
    const string& getFirstName()const;
    const string& getLastName()const;

    private:
    BinarySearchTree<electricityData> householdElectricityData;
    string lastName, firstName;
    size_t ID;
    vector<int> familyAges;
    District district;
    static size_t nextID;
};

#endif
