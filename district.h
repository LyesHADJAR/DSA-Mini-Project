#include <iostream>
#include <vector>
#include "household.h"
using namespace std;

class District {
    public:
    District(const string&);
    void addHouseholder(const Household&);
    void removeHouseholder(const Household&);
    Household* findHouseholderById(int customerId);

    private:
    string districtName;
    vector<Household> districtHouseholders;
}; 

District::District(const string& name){
    districtName = name;
}

void District:: addHouseholder(const Household& customer) {
    if(districtHouseholders.size() == 0) districtHouseholders.push_back(customer);
    else {
        vector<Household>::const_iterator iter = districtHouseholders.begin();
        while((*iter).getId() < customer.getId()){
            iter++;
        }
        districtHouseholders.insert(iter,customer);
    }
}

void District::removeHouseholder(const Household& customer){
    vector<Household>::const_iterator iter = districtHouseholders.begin();
        do {
            if ((*iter).getId() == customer.getId()) {
                districtHouseholders.erase(iter);
                break;
            }
        } while(iter != districtHouseholders.end());
}

Household* findHouseholderById(int customerId) {
        auto it = find_if(districtHouseholders.begin(), districtHouseholders.end(), [&](const Household& customer) {
            return customer.getId() == customerId;
        });
        if (it != districtHouseholders.end()) {
            return &(*it);
        }
        return nullptr;
}