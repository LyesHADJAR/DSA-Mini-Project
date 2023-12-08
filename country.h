#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "region.h"
using namespace std;

class Country {
    public:
    Country(const string&);
    void addRegion(const Region&);
    string getCountryName() const ;
    void setCountryName(string);
    BinarySearchTree<Region>::BinaryNode* findRegion(const Region &) ;
    void addDepartment(Department&);
    void findTop10(BinarySearchTree<Department>::BinaryNode*, vector<Department>, int)const;
    void findBottom10(BinarySearchTree<Department>::BinaryNode*, vector<Department>, int)const;
    void updateBudgets();

    private:
    string countryName;
    BinarySearchTree<Region> countryRegions;
    BinarySearchTree<Department> countryDepartments;//!!!!!!!!!!--- must sort it according to the performance
    vector<Department> top10;
    vector<Department> bottom10;
};

#endif