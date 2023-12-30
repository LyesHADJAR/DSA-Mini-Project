#include "city.h"

#include <utility>

City::City(const string &newCity, string ID, Region *r) : cityName{newCity}, region(r), cityID("0") {
    regionID = std::move(ID);
    cityDistrictsNextID = 1;
    if (!newCity.empty()) setID();
    citydistricts.resize(1);
    cityDepartment = new Department(cityName, this);
}

City::~City() {
    citydistricts.clear();
    districtIndexMap.clear();
}

void City::setCityName(const string &city) {
    cityName = city;
}

string City::getCityName() const {
    return cityName;
}

void City::addDistrict(District *newDistrict) {
    int district_id = stoi(newDistrict->getDistrict_ID().substr(9, 3));
    citydistricts.push_back(newDistrict);
    // cout<<cityID<<"   "<<citydistricts.size()<<"    "<<citydistricts[district_id]->getDistrict_ID()<<endl;
    districtIndexMap[newDistrict->getDistrict_Name()] = district_id;
}

District *City::findDistrictByID(string id) const {
    if (id.substr(0, 9) == cityID) {
        int district_id = stoi(id.substr(9, 3));
        return citydistricts[district_id];
    } else return NULL;
}

District *City::findDistrictByName(const string &name) const {
    auto it = districtIndexMap.find(name);
    if (it != districtIndexMap.end()) {
        size_t districtIndex = it->second;
        return citydistricts[districtIndex];
    } else return NULL;
}

string City::getRegionID() const {
    return regionID;
}

string City::getID() {
    return cityID;
}

void City::setID() {
    size_t newID = region->getNextID();
    cityID = regionID;
    if (newID / 10 == 0) cityID += "00" + to_string(newID);
    else if (newID / 100 == 0) cityID += "0" + to_string(newID);
    else cityID += to_string(newID);
    region->incrementNextID();
//     region->getCountry()->addCity(this);
    region->addCity(this);
}

long double City::cityYearlyBill(int year) {
    long double bill = 0;
    // cout<<"size "<<citydistricts.size()<<endl;
    for (int i = 1; i < citydistricts.size(); i++) {
        bill += citydistricts[i]->districtYearlyBill(year);
    }
    return bill;
}

size_t City::getNextID() const {
    return cityDistrictsNextID;
}

void City::incrementNextID() {
    cityDistrictsNextID++;
}

HouseHold *City::cityCandidate(int year, int month, HouseHold *max) {

    if (citydistricts.size() == 1) { return nullptr; }
    else
        max = citydistricts[1]->districtCandidate(year, month, citydistricts[1]->getRoot(),
                                                  citydistricts[1]->getRoot());
    HouseHold *candidate;
    for (int i = 1; i < citydistricts.size(); i++) {
        candidate = citydistricts[i]->districtCandidate(year, month, citydistricts[i]->getRoot());
        if (max->getProductionInRange(year, 1, 1, year, month, 31) <
            candidate->getProductionInRange(year, 1, 1, year, month, 31))
            max = candidate;
    }
    return max;
}

void City::setRegionID(string id) {
    regionID = std::move(id);
}

Region *City::getRegion() {
    return region;
}

nlohmann::json City::cityToJson() const {
    nlohmann::json jsonFile;

    jsonFile["City_Name"] = cityName;
    jsonFile["City_ID"] = cityID;
    jsonFile["Department"] = cityDepartment->departmentToJson();

    std::vector<nlohmann::json> DistrictsJson;
    DistrictsJson.reserve(citydistricts.size());
    for (const auto &district: citydistricts) {
        DistrictsJson.push_back(district->DistrictToJson());
    }

    jsonFile["Districts"] = DistrictsJson;

    return jsonFile;
}

City City::cityFromJson(const nlohmann::json &jsonData) {
    if (!jsonData.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }
    City city(
            jsonData["City_Name"].get<std::string>(),
            jsonData["City_ID"].get<std::string>(),
            nullptr
    );
    city.cityDepartment->setBudget(jsonData["Budget"].get<float>());
    city.cityDepartment->setAmountSpent(jsonData["AmountSpent"].get<float>());
    city.cityDepartment->setRanking(jsonData["Ranking"].get<float>());

    if (jsonData.find("Districts") != jsonData.end() && jsonData["Districts"].is_array()) {
        for (const auto &districtJson: jsonData["Districts"]) {
            District newDistrict(districtJson["District_Name"], districtJson["District_ID"], &city);
            city.addDistrict(&newDistrict);
        }
    };
    return city;
}
