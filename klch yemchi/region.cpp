#include "region.h"
#include <utility>

Region::Region(const string &name, string ID, Country *c) : country(c) {
    RegionName = name;
    countryID = std::move(ID);
    regionCitiesNextID = 1;
    if (!name.empty()) setId();
    regionCities.resize(1);
}

Region::~Region() {
    regionCities.clear();
    cityIndexMap.clear();
}

void Region::addCity(City *newCity) {
    int city_id = stoi(newCity->getID().substr(6, 3));
    regionCities.push_back(newCity);
    cityIndexMap[newCity->getCityName()] = city_id;
}

City *Region::findCityByName(const string &name) const {
    auto it = cityIndexMap.find(name);
    if (it != cityIndexMap.end()) {
        size_t cityIndex = it->second;
        return regionCities[cityIndex];
    } else return nullptr;
}

City *Region::findCityByID(const string &id) const {
    if (id.substr(0, 6) == IDregion) {
        int city_id = stoi(id.substr(6, 3));
        return regionCities[city_id];
    } else return nullptr;
}

string Region::getRegionName() const {
    return RegionName;
}

void Region::setRegionName(string Region) {
    RegionName = std::move(Region);
}


void Region::setId() {
    size_t newID = country->getNextID();
    IDregion = countryID;
    if (newID / 10 == 0) IDregion += "00" + to_string(newID);
    else if (newID / 100 == 0) IDregion += "0" + to_string(newID);
    else IDregion += to_string(newID);
    country->incrementNextID();
    country->addRegion(this);
}

string Region::getId() const {
    if (this == nullptr) throw logic_error("getId() called on a NULL object");
    return IDregion;
}

string Region::getCountryID() const {
    return countryID;
}

size_t Region::getNextID() const {
    return regionCitiesNextID;
}

void Region::incrementNextID() {
    regionCitiesNextID++;
}

Country *Region::getCountry() {
    return country;
}

nlohmann::json Region::regionToJson() const {
    nlohmann::json jsonFile;

    jsonFile["Region_Name"] = RegionName;
    jsonFile["Region_ID"] = IDregion;

    std::vector<nlohmann::json> cities_Json;
    cities_Json.reserve(regionCities.size());
    for (const auto &cityJson: regionCities) {
        cities_Json.push_back(cityJson->cityToJson());
    }

    jsonFile["Cities"] = cities_Json;
    return jsonFile;
}

Region Region::regionFromJson(const nlohmann::json &jsonFile) {
    if (!jsonFile.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }
    Region region(
            jsonFile["Region_Name"].get<std::string>(),
            jsonFile["Region_ID"].get<std::string>(),
            nullptr
    );
    if (jsonFile.find("Cities") != jsonFile.end() && jsonFile["Cities"].is_array()) {
        for (const auto &cityJson: jsonFile["Cities"]) {
            City newCity(cityJson["City_Name"], cityJson["City_ID"], &region);
            region.addCity(&newCity);
        }
    }

    return region;
}
