#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <unordered_map>
#include "region.h"

using namespace std;

class Country {
    public:
    explicit Country(const string&);
    void addRegion(const Region&);
    string getCountryName() const ;
    void setCountryName(string);
    Region findRegionByName(const string&)const ;
    Region findRegionByID(size_t)const;
    void addDepartment(Department&);
    Department findDepartmentByName(const string&)const;
    Department findDepartmentByID(size_t)const;
    size_t getCountryID() const;
    // void findTop10(BinarySearchTree<Department>::BinaryNode*, vector<Department>, int)const;
    // void findBottom10(BinarySearchTree<Department>::BinaryNode*, vector<Department>, int)const;
    // void updateBudgets();

    private:
    string countryName;
    size_t countryID;
    vector<Region> countryRegions;
    unordered_map<string, size_t> regionIndexMap;
    vector<Department> countryDepartments;
    unordered_map<string, size_t> departmentIndexMap;
    vector<Department> top10;
    vector<Department> bottom10;

    static size_t country_hash(const string&);
};

#endif