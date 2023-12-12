#ifndef City_H
#define City_H

#include <iostream>
#include "region.h"
#include "district.h"
#include "Department.h"
using namespace std;

class City {
    private:
        string cityName;
        vector<District> citydistricts;
        unordered_map<string,size_t> districtIndexMap;
        Department Department_Of_This_City;
        Region region;
        size_t cityID;
        static size_t city_hash(const string&);

    public:
        City(string , Region&);
        void setCityName(const string&);
        string getCityName()const;
        void addDistrict(const District &);
        District findDistrictByName(const string&)const ;
        District findDistrictByID(size_t)const;
        // float computeCityPerformance(BinarySearchTree<District>::BinaryNode*)const;
        // BinarySearchTree<District>::BinaryNode* getRoot();
        Region getRegion()const;
        size_t getCityID()const;
        // bool operator<(const City&)const;
        // bool operator>(const City&)const;
        // bool operator>=(const City&)const;
        // bool operator<=(const City&)const;
        // bool operator==(const City&)const;
        // bool operator!=(const City&)const;
};

#endif