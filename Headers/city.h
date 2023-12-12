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
        string regionID;
        string cityID;
        static size_t nextID;
    
    
    public:
        City(const string&, string);
        void setCityName(const string&);
        string getCityName()const;
        void addDistrict(const District &);
        District findDistrictByName(const string&)const ;
        District findDistrictByID(size_t)const;
        string getRegionID()const;
        string getID()const;
        void setID();
};

#endif