#include <iostream>
#include <vector>
#include<algorithm>
#include "Household.h"
#include"BinarySearchTree.h"
using namespace std;

class District {
public:
    District(const string&);
    void addHouseholder(const Household&);
    void removeHouseholder(const Household&);
    Household* findHouseholder(const Household &);

private:
    string districtName;
    BinarySearchTree<Household> districtHouseholders;
}; 

District::District(const string& name="") : districtName(name) {}

void District::addHouseholder(const Household& customer) {
    districtHouseholders.insert(customer);
}

void District::removeHouseholder(const Household& customer) {
    districtHouseholders.remove(customer);
}

Household* District::findHouseholder(const Household & customer) {
    return districtHouseholders.findNode(customer);
}