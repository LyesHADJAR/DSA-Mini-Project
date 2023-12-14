#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "region.h"
using namespace std;

class Country {
    public:
    Country(const string&);
    void addRegion(const Region&);
    string getCountryName() const ;
    void setCountryName(string);
    Region findRegionByName(const string&)const ;
    Region findRegionByID(size_t)const;
    void addDepartment(Department&);
    Department findDepartmentByName(const string&)const;
    Department findDepartmentByID(size_t)const;
    void setID();
    string getID()const;
    void endOfTheYear(int);

    private:
    string countryName;
    vector<Region> countryRegions;
    unordered_map<string, size_t> regionIndexMap;
    vector<Department> countryDepartments;
    unordered_map<string, size_t> departmentIndexMap;
    static double nextID;
    string countryID;
    void sortDepartments()const;
};

#endif