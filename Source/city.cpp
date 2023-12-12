#include "city.h"

#include <utility>

size_t City::city_hash(const std::string &city_name) {
    size_t hashValue = 0;

    for (char ch: city_name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

City::City(string newCity, Region &reg) : cityName{std::move(newCity)}, region(reg),
                                               Department_Of_This_City(newCity, *this) {
    reg.addCity(*this);
    cityID = reg.getRegionId() + city_hash(cityName) * 1000000;
}

void City::setCityName(const string &city) {
    cityName = city;
}

string City::getCityName() const {
    return cityName;
}

void City::addDistrict(const District &newDistrict) {
    citydistricts[newDistrict.getDistrictID()] = newDistrict;
    districtIndexMap[newDistrict.getDistrict_Name()] = newDistrict.getDistrictID();
}

District City::findDistrictByID(size_t id) const {
    return citydistricts[id];
}

District City::findDistrictByName(const string &name) const {
    auto it = districtIndexMap.find(name);
    if (it != districtIndexMap.end()) {
        size_t districtIndex = it->second;
        return citydistricts[districtIndex];
    } else return;
}

// float City::computeCityPerformance(BinarySearchTree<District>::BinaryNode* districts)const {
//    return districts->element.computeDistrictPerformance(districts->element.getRoot())+ districts->left->element.computeDistrictPerformance(districts->left->element.getRoot()) + districts->right->element.computeDistrictPerformance(districts->right->element.getRoot());
// }

// BinarySearchTree<District>::BinaryNode* City:: getRoot() {
//         return Citydistricts.getRoot();
// }

Region City::getRegion() const {
    return this->region;
}

size_t City::getCityID() const {
    return cityID;
}

// bool City::operator<(const City& c)const{
//         return cityName < c.cityName;
// }

// bool City::operator>(const City& c)const {
//         return cityName > c.cityName;
// }

// bool City::operator>=(const City& c)const {
//         return cityName >= c.cityName;
// }

// bool City::operator<=(const City& c)const {
//         return cityName <= c.cityName;
// }

// bool City::operator==(const City& c)const {
//         return cityName == c.cityName;
// }

// bool City::operator!=(const City& c)const {
//         return cityName != c.cityName;
// }