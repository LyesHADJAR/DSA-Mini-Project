#ifndef DISTRICT_H
#define DISTRICT_H

#include"HouseHold.h"
#include "city.h"
#include"BST.h"

class District {
private:
    District(const string &District_Name, double spendBudget, const City& c);

    size_t DistrictID;
    string District_Name;
    static size_t district_hash(const string&);
    City city;
    BST HouseHold_Tree;
    double spendBudget;
    void inOrderTraversalForConsumption(BSTNode *currentNode, double &totalConsumption) const;
    void inOrderTraversalForProduction(BSTNode *currentNode, double &totalProduction) const;

public :
    explicit District(const string& District_Name, double spendBudget);
    ~District();
    size_t getDistrictID() const;
    string getDistrict_Name() const;
    void setDistrict_Name(string District_Name);
    void addHouseHold(HouseHold &HouseHold);
    void removeHouseHold(double);
    void updateHouseHold(const HouseHold &, double);   //!!!!!!!!!!!
    HouseHold *searchHouseHold(double HouseHold_ID);
    double getDistrictConsumption() const;
    double getDistrictProduction() const;
    //double spendBudget()const;
    // double generateDistrictId() const ;
    HouseHold *searchHouseHold(size_t HouseHold_ID);
};

#endif
