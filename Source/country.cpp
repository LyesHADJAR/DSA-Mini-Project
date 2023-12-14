#include "country.h"

double Country::nextID = 1;   //////!!!!!!!! come back here after starting files
Country::Country(const string& name){
    setCountryName(name);
    setID();
}

void Country:: addRegion(const Region& newRegion) {
    int region_id = stoi(newRegion.getId().substr(3,3));
    countryRegions[region_id]= newRegion;
    regionIndexMap[newRegion.getRegionName()] = region_id;
}

string Country::getCountryName()const {
    return countryName; 
}
void Country::setCountryName(string Country){
    countryName=Country;  
}

Region Country::findRegionByName(const string& regionName)const {
    auto it = regionIndexMap.find(regionName);
    if (it != regionIndexMap.end()) {
            size_t regionIndex = it->second;
            return countryRegions[regionIndex];
    }
    else return;
}

Region Country::findRegionByID(size_t id)const {
    return countryRegions[id];
}

void Country::addDepartment(Department& dep) {
    int department_id = stoi(dep.getID().substr(6,3));
    countryDepartments[department_id]= dep;
    departmentIndexMap[dep.getName()] = department_id;
}

Department Country::findDepartmentByName(const string& name)const {
    auto it = regionIndexMap.find(name);
    if (it != regionIndexMap.end()) {
            size_t regionIndex = it->second;
            return countryDepartments[regionIndex];
    }
    else return;
}

Department Country::findDepartmentByID(size_t id)const {
    return countryDepartments[id];
}

void Country::setID() {
    if(nextID/10 == 0) countryID = "00"+ to_string(nextID);
    else if (nextID/100==0) countryID = "0"+to_string(nextID);
    else countryID = to_string(nextID);
    nextID++;
}

string Country::getID()const {
    return countryID;
}

void Country::sortDepartments()const {
    sort(countryDepartments.begin(), countryDepartments.end());
}

void Country::endOfTheYear(int year){
    for(int i=0; i<countryDepartments.size();i++) countryDepartments[i].setCurrentYear(year);
    sortDepartments();
    countryDepartments[0].decreaseBudget(15);
    for(int i=1; i<10; i++) countryDepartments[i].decreaseBudget(10);
    countryDepartments[countryDepartments.size()-1].increaseBudget(15);
    for(int i=countryDepartments.size()-2; i>countryDepartments.size()-11; i--) countryDepartments[i].increaseBudget(10);
}