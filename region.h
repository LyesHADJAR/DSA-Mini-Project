#ifndef Region_H
#define Region_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "city.h"
#include "country.h"
using namespace std;

class Region {
    public:
    Region(const string&, Country&);
    void addCity(const City&);
    string getRegionName() const ;
    void setRegionName(string);
    BinarySearchTree<City>::BinaryNode* findCity(const City &) ;
    Country getCountry()const;

    private:
    string RegionName;
    BinarySearchTree<City> RegionCities;
    Country country;
};

#endif