#ifndef City_H
#define City_H

#include <iostream>
#include "region.h"
#include "district.h"
#include "Department.h"
#include "binarySearchTree.h"
using namespace std;

class City {
    private:
        string City_Name;
        BinarySearchTree<District> Citydistricts;
        Department Department_Of_This_City;
        Region region;
    public:
        City(const string&, Region&);
        void setCityName(const string&);
        string getCityName()const;
        void addDistrict(const District &);
        BinarySearchTree<District>::BinaryNode* findDistrict(const District &) ;
        float computeCityPerformance(BinarySearchTree<District>::BinaryNode*)const;
        BinarySearchTree<District>::BinaryNode* getRoot();
        Region getRegion()const;
};

#endif