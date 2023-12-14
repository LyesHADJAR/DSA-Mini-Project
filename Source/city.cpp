#include "city.h"

size_t City::nextID = 1;

City::City(const string& newCity="", string ID):cityName{newCity}, Department_Of_This_City(newCity,this){
        setID();
        regionID = ID ;
}

void City:: setCityName(const string& city){
        cityName=city;
}

string City::getCityName()const {
            return cityName;
}

void City::addDistrict(const District & newDistrict) {
        int district_id = stoi(newDistrict.getDistrict_ID().substr(9,3));
        citydistricts[district_id] = newDistrict;
        districtIndexMap[newDistrict.getDistrict_Name()] = district_id;
}

District City::findDistrictByID(size_t id)const{
        return citydistricts[id];
}

District City::findDistrictByName(const string& name)const {
        auto it = districtIndexMap.find(name);
        if (it != districtIndexMap.end()) {
            size_t districtIndex = it->second;
            return citydistricts[districtIndex];
    }
    else return;
}

string City::getRegionID()const{
    return regionID;
}

string City::getID()const {
        return cityID;
}

void City::setID() {
    cityID= regionID;
    if(nextID/10 == 0) cityID += "00"+ to_string(nextID);
    else if (nextID/100==0) cityID += "0"+to_string(nextID);
    else cityID += to_string(nextID);
    nextID++;
}

long double City::cityYearlyBill(int year)const {
        long double bill = 0;
        for(int i=0; i< citydistricts.size();i++) {
                bill+= citydistricts[i].districtYearlyBill(year);
        }
        return bill;
}