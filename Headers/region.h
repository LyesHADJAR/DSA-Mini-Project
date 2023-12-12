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
    City findCityByName(const string&)const ;
    City findCityByID(size_t)const;
    Country getCountry()const;
    // bool operator<(const Region&)const;
    // bool operator>(const Region&)const;
    // bool operator<=(const Region&)const;
    // bool operator>=(const Region&)const;
    // bool operator==(const Region&)const;
    // bool operator!=(const Region&)const;
    size_t getRegionId() const;

    private:
    string RegionName;
    vector<City> regionCities;
    unordered_map<string,size_t> cityIndexMap;
    Country country;
    size_t RegionID;

    static size_t region_hash(const string&);
};

#endif
