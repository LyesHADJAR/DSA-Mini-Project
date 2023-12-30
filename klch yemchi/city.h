#ifndef City_H
#define City_H

#include <iostream>
#include "District.h"
#include "region.h"
#include "Department.h"
#include <unordered_map>

using namespace std;

class Region;

class District;

class HouseHold;

class Department;

class City {
private:
    string cityName;
    vector<District *> citydistricts;
    unordered_map<string, size_t> districtIndexMap;
    string regionID;
    string cityID;
    Region *region;
    size_t cityDistrictsNextID;
    Department *cityDepartment;

public:
    explicit City(const string & = "", string = "", Region * = nullptr);

    ~City();

    void setCityName(const string &);

    string getCityName() const;

    void addDistrict(District *);

    District *findDistrictByName(const string &) const;

    District *findDistrictByID(string) const;

    string getRegionID() const;

    string getID();

    void setID();

    long double cityYearlyBill(int);

    size_t getNextID() const;

    void incrementNextID();

    HouseHold *cityCandidate(int, int, HouseHold * = nullptr);

    void setRegionID(string);

    Region *getRegion();

    nlohmann::json cityToJson() const;

    static City cityFromJson(const nlohmann::json &jsonFile);
};

#endif
