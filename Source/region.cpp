#include "region.h"

size_t Region::nextID = 0;

Region::Region(const string& name, Country& c): country(c){
    RegionName = name;
    setId();
}

void Region:: addCity(const City& newCity) {
    regionCities[newCity.getID()]= newCity;
    cityIndexMap[newCity.getCityName()] = newCity.getID();
}

City Region::findCityByName(const string& name)const {
    auto it = cityIndexMap.find(name);
    if (it != cityIndexMap.end()) {
            size_t cityIndex = it->second;
            return regionCities[cityIndex];
    }
    else return;
}

City Region::findCityByID(size_t id)const {
    return regionCities[id];
}

string Region::getRegionName()const {
    return RegionName; 
}
void Region::setRegionName(string Region){
    RegionName=Region;
}

Country Region::getCountry()const {
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

void Region::setId(){
    IDregion = ++nextID;
}

size_t Region::getId()const {
    return IDregion;
}

