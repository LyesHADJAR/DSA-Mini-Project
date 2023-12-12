#include "region.h"
#include <utility>

size_t Region::region_hash(const std::string &region_name) {
    size_t hashValue = 0;

    for (char ch: region_name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

Region::Region(const string &name, Country &c) : country(c) {
    RegionName = name;
    RegionID = c.getCountryID() + region_hash(RegionName) * 1000000000;
}

void Region::addCity(const City &newCity) {
    regionCities[newCity.getCityID()] = newCity;
    cityIndexMap[newCity.getCityName()] = newCity.getCityID();
}

City Region::findCityByName(const string &name) const {
    auto it = cityIndexMap.find(name);
    if (it != cityIndexMap.end()) {
        size_t cityIndex = it->second;
        return regionCities[cityIndex];
    } else return;
}

City Region::findCityByID(size_t id) const {
    return regionCities[id];
}

string Region::getRegionName() const {
    return RegionName;
}

void Region::setRegionName(string Region) {
    RegionName = std::move(Region);
}

Country Region::getCountry() const {
    return this->country;
}

// bool Region::operator<(const Region& reg)const {
//     return RegionName < reg.RegionName;
// }

// bool Region::operator>(const Region& reg)const {
//     return RegionName > reg.RegionName;
// }

// bool Region::operator<=(const Region& reg)const {
//     return RegionName <= reg.RegionName;
// }

// bool Region::operator>=(const Region& reg)const {
//     return RegionName >= reg.RegionName;
// }

// bool Region::operator==(const Region& reg)const {
//     return RegionName == reg.RegionName;
// }

// bool Region::operator!=(const Region& reg)const {
//     return RegionName != reg.RegionName;
// }


size_t Region::getRegionId() const {
    return RegionID;
}

