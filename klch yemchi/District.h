#ifndef DISTRICT_H
#define DISTRICT_H

#include"HouseHold.h"
#include"BST.h"
#include "city.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class HouseHold;

class City;

class District {
private:
    City *city;
    string District_ID;
    string cityID;
    string District_Name;
    BST<HouseHold> HouseHold_Tree;
    double spendBudget = 0;

    void inOrderTraversalForConsumption(BSTNode<HouseHold> *currentNode, double &totalConsumption);

    void inOrderTraversalForProduction(BSTNode<HouseHold> *currentNode, double &totalProduction);

    vector<bool> isHouseholdIDUsed;

    BSTNode<HouseHold> *districtCandidateHelper(int, int, BSTNode<HouseHold> *, BSTNode<HouseHold> *);

public :
    explicit District(const string &, string= "", City * = nullptr);

    ~District();

    string getDistrict_ID() const;

    string getDistrict_Name() const;

    void setDistrict_ID();

    void setDistrict_Name(string);

    void addHouseHold(const HouseHold &);

    void removeHouseHold(double);

    void updateHouseHold(const HouseHold &, double);   //!!!!!!!!!!!
    HouseHold *searchHouseHold(string);

    double getDistrictConsumption();

    double getDistrictProduction();

    double amountSpent();

    long double districtYearlyBill(int);

    bool isIDUsed(int);

    HouseHold *districtCandidate(int, int, BSTNode<HouseHold> *, BSTNode<HouseHold> * = NULL);

    BSTNode<HouseHold> *getRoot() const;

    nlohmann::json DistrictToJson() const;

    static District DistrictFromJson(const nlohmann::json &jsonData);

};

#endif