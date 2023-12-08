#ifndef District_H
#define District_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "household.h"
#include "city.h"
#include"BinarySearchTree.h"
using namespace std;

class District {
public:
    District(const string&, City&);
    void addHouseholder(const Household&);
    void removeHouseholder(const Household&);
    BinarySearchTree<Household>::BinaryNode* findHouseholder(const Household &);
    float computeDistrictPerformance(BinarySearchTree<Household>::BinaryNode*)const;
    BinarySearchTree<Household>::BinaryNode* getRoot();

private:
    string districtName;
    BinarySearchTree<Household> districtHouseholders;
    City city;
}; 

#endif

