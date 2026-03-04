#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "region.h"
#include "Department.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Region;

class HouseHold;

class Department;

class Country {
public:
    explicit Country(const string &);

    ~Country();

    void addRegion(Region *);

    string getCountryName() const;

    void setCountryName(string);

    Region *findRegionByName(const string &) const;

    Region *findRegionByID(const string &) const;

    void addDepartment(Department *);

    Department *findDepartmentByName(const string &) const;

    Department *findDepartmentByID(const string &) const;

    void setID();

    string getID() const;

    void endOfTheYear(int);

    size_t getNextID() const;

    void incrementNextID();

    static int stringToInt(const string &str);

    HouseHold *nationalPrizeWinner(int, int);

    nlohmann::json countryToJson() const;

    static Country countryFromJson(const nlohmann::json &jsonFile);


private:
    string countryName;
    vector<Region *> countryRegions;
    unordered_map<string, size_t> regionIndexMap;
    vector<Department *> countryDepartments;
    unordered_map<string, size_t> DepartmentIndexMap;
    static size_t nextID;
    string countryID;
    size_t countryRegionsNextID;

    void sortDepartments(int);

};

#endif
