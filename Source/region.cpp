#include "region.h"

size_t Region::nextID = 1;

Region::Region(const string& name, string ID){
    RegionName = name;
    countryID = ID;
    setId();
}

void Region:: addCity(const City& newCity) {
    int city_id = stoi(newCity.getID().substr(6,3));
    regionCities[city_id]= newCity;
    cityIndexMap[newCity.getCityName()] = city_id;
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


void Region::setId(){
    IDregion= countryID;
    if(nextID/10 == 0) IDregion += "00"+ to_string(nextID);
    else if (nextID/100==0) IDregion += "0"+to_string(nextID);
    else IDregion += to_string(nextID);
    nextID++;
}

string Region::getId()const {
    return IDregion;
}

string Region::getCountryID()const {
    return countryID;
}
