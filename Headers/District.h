#ifndef DISTRICT_H
#define DISTRICT_H

#include"HouseHold.h"
#include"BST.h"

class District {
    static size_t nextID;
    string District_ID;
    string cityID;
    string District_Name;
    BST HouseHold_Tree;
    double spendBudget;
    void inOrderTraversalForConsumption(BSTNode* currentNode, double& totalConsumption) const ;
    void inOrderTraversalForProduction(BSTNode* currentNode, double& totalProduction) const ;

    public :
    District(string, string);
    ~District();
    string getDistrict_ID()const ;
    string getDistrict_Name() const ;
    void setDistrict_ID();
    void setDistrict_Name(string);
    void addHouseHold(HouseHold&);
    void removeHouseHold(double);
    void updateHouseHold(const HouseHold& ,double);   //!!!!!!!!!!!
    HouseHold* searchHouseHold(double);
    double getDistrictConsumption() const ;
    double getDistrictProduction() const ;
    double spendBudget()const;
    long double districtYearlyBill(int)const;
    
    // double generateDidtrictId() const ;
};


#endif
