#include "region.h"

Region::Region(const string& name, Country& c): country(c){
    RegionName = name;
}

void Region:: addCity(const City& NewCity) {
    RegionCities.insert(NewCity);
    //sortDepartmentsByBudget();
}

string Region::getRegionName()const {
    return RegionName; 
}
void Region::setRegionName(string Region){
    RegionName=Region;
}

BinarySearchTree<City>::BinaryNode* Region::findCity(const City& CitytName) {
    
    return RegionCities.findNode(CitytName);
        
}

Country Region::getCountry()const {
    return this->country;
}