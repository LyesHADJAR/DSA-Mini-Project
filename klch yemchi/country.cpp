#include "country.h"
#include <utility>

size_t Country::nextID = 1;   //////!!!!!!!! come back here after starting files
Country::Country(const string &name) {
    setCountryName(name);
    countryRegionsNextID = 1;
    setID();
    countryRegions.resize(1);
    countryDepartments.resize(1);
}

Country::~Country() = default;

void Country::addRegion(Region *newRegion) {
    int region_id = stoi(newRegion->getId().substr(3, 3));
    countryRegions.push_back(newRegion);
    regionIndexMap[newRegion->getRegionName()] = region_id;
}

string Country::getCountryName() const {
    return countryName;
}

void Country::setCountryName(string Country) {
    countryName = std::move(Country);
}

Region *Country::findRegionByName(const string &regionName) const {
    auto it = regionIndexMap.find(regionName);
    if (it != regionIndexMap.end()) {
        size_t regionIndex = it->second;
        return countryRegions[regionIndex];
    } else return nullptr;
}

Region *Country::findRegionByID(const string &id) const {
    if (id.substr(0, 3) == countryID) {
        int region_id = stoi(id.substr(3, 3));
        return countryRegions[region_id];
    } else return nullptr;
}

void Country::addDepartment(Department *dep) {
    int Department_id = stoi(dep->getID().substr(6, 3));
    countryDepartments.push_back(dep);
    // countryDepartments[Department_id]->setRegionID(dep->getRegionID());
    DepartmentIndexMap[dep->getName()] = Department_id;
}

Department *Country::findDepartmentByName(const string &name) const {
    auto it = DepartmentIndexMap.find(name);
    if (it != DepartmentIndexMap.end()) {
        size_t regionIndex = it->second;
        return countryDepartments[regionIndex];
    } else return nullptr;
}

Department *Country::findDepartmentByID(const string &id) const {
    if (id.substr(0, 3) == countryID) {
        int Department_id = stringToInt(id.substr(6, 3));
        return countryDepartments[Department_id];
    } else return nullptr;
}

void Country::setID() {
    if (nextID / 10 == 0) countryID = "00" + to_string(nextID);
    else if (nextID / 100 == 0) countryID = "0" + to_string(nextID);
    else countryID = to_string(nextID);
    nextID++;
}

string Country::getID() const {
    return countryID;
}

void Country::sortDepartments(int year) {
    size_t n = countryDepartments.size();

    for (size_t i = 1; i < n - 1; ++i) {
        size_t minIndex = i;

        for (size_t j = i + 1; j < n; ++j) {
            // Assuming Department class has a function getPerformance() that returns performance
            if ((*(countryDepartments[j])).getPerformance(year) <
                (*(countryDepartments[minIndex])).getPerformance(year)) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(countryDepartments[i], countryDepartments[minIndex]);
        }
    }
}

void Country::endOfTheYear(int year) {
    sortDepartments(year);
    // cout<<"________"<<endl;
    // for(int i=1; i<countryDepartments.size();i++) {cout<<countryDepartments[i]->getPerformance(year)<<"  "<<countryDepartments[i]->getName()<<endl;}
    countryDepartments[1]->decreaseBudget(15);
    for (int i = 2; i <= 10; i++) countryDepartments[i]->decreaseBudget(10);
    countryDepartments[countryDepartments.size() - 1]->increaseBudget(15);
    for (size_t i = countryDepartments.size() - 2; i > countryDepartments.size() - 11; i--)
        countryDepartments[i]->increaseBudget(10);
    cout << "WINNER: " << countryDepartments[countryDepartments.size() - 1]->getName() << endl;
}

size_t Country::getNextID() const {
    return countryRegionsNextID;
}

void Country::incrementNextID() {
    countryRegionsNextID++;
}

int Country::stringToInt(const string &str) {
    std::stringstream ss(str);
    int result = 0;
    ss >> result;
    return result;
}

HouseHold *Country::nationalPrizeWinner(int year, int month) {
    HouseHold *max = nullptr;
    if (countryDepartments.empty()) return nullptr;
    else max = countryDepartments[1]->departmentCandidate(year, month);
    HouseHold *candidate;
    for (int i = 1; i < countryDepartments.size(); i++) {
        candidate = countryDepartments[i]->departmentCandidate(year, month);
        if (max->getProductionInRange(year, 1, 1, year, month, 31) <
            candidate->getProductionInRange(year, 1, 1, year, month, 31))
            max = candidate;
    }
    return max;
}

nlohmann::json Country::countryToJson() const {
    nlohmann::json jsonFile;

    jsonFile["Country_Name"] = countryName;
    jsonFile["Country_ID"] = countryID;

    std::vector<nlohmann::json> regions_Json;
    regions_Json.reserve(countryRegions.size());
    for (const auto &regionJson: countryRegions) {
        regions_Json.push_back(regionJson->regionToJson());
    }

    jsonFile["Regions"] = regions_Json;
    return jsonFile;
}

Country Country::countryFromJson(const nlohmann::json &jsonFile) {
    if (!jsonFile.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }
    Country country(
            jsonFile["Country_Name"].get<std::string>());

    if (jsonFile.find("Regions") != jsonFile.end() && jsonFile["Regions"].is_array()) {
        for (const auto &regionJson: jsonFile["Regions"]) {
            Region newRegion(regionJson["Region_Name"], regionJson["Region_ID"], &country);
            country.addRegion(&newRegion);
        }
    }

    return country;
}

