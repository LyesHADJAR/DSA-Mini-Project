#ifndef DISTRICT_H
#define DISTRICT_H

#include"HouseHold.h"
#include"BST.h"

class District {
    static size_t nextID;
    double District_ID;
    string District_Name;
    BST HouseHold_Tree;
    double spendBudget;
    void inOrderTraversalForConsumption(BSTNode* currentNode, double& totalConsumption) const ;
    void inOrderTraversalForProduction(BSTNode* currentNode, double& totalProduction) const ;

    public :
    District( string District_Name);
    ~District();
    double getDistrict_ID()const ;
    string getDistrict_Name() const ;
    void setDistrict_ID();
    void setDistrict_Name(string District_Name);
    void addHouseHold(HouseHold &HouseHold);
    void removeHouseHold(double);
    void updateHouseHold(const HouseHold& ,double);   //!!!!!!!!!!!
    HouseHold* searchHouseHold(double HouseHold_ID);
    double getDistrictConsumption() const ;
    double getDistrictProduction() const ;
    double spendBudget()const;
    
    // double generateDidtrictId() const ;
};


#endif
