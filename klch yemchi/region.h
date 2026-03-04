#ifndef Region_H
#define Region_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "city.h"
#include "country.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Country;

class Region {
public:
    explicit Region(const string & = "", string= "", Country * = nullptr);

    ~Region();

    void addCity(City *);

    string getRegionName() const;

    void setRegionName(string);

    City *findCityByName(const string &) const;

    City *findCityByID(const string &) const;

    string getCountryID() const;

    string getId() const;

    void setId();

    size_t getNextID() const;

    void incrementNextID();

    Country *getCountry();

    nlohmann::json regionToJson() const;

    static Region regionFromJson(const nlohmann::json &jsonFile);


private:
    string RegionName;
    vector<City *> regionCities;
    unordered_map<string, size_t> cityIndexMap;
    string countryID;
    string IDregion;
    size_t regionCitiesNextID;
    Country *country;
};

#endif
