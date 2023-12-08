#include "city.h"

City::City(const string& NewCity="", Region& reg):City_Name{NewCity}, region(reg){
        Department_Of_This_City.setDepartmentName(NewCity);
        reg.addCity(*this);
}

void City:: setCityName(const string& City){
        City_Name=City;
}

string City::getCityName()const {
            return City_Name;
}

void City::addDistrict(const District & NewDistrict) {
            Citydistricts.insert(NewDistrict);
}

BinarySearchTree<District>::BinaryNode* City::findDistrict(const District & DistrictValue) {
    return Citydistricts.findNode(DistrictValue);
}

float City::computeCityPerformance(BinarySearchTree<District>::BinaryNode* districts)const {
   return districts->element.computeDistrictPerformance(districts->element.getRoot())+ districts->left->element.computeDistrictPerformance(districts->left->element.getRoot()) + districts->right->element.computeDistrictPerformance(districts->right->element.getRoot());
}

BinarySearchTree<District>::BinaryNode* City:: getRoot() {
        return Citydistricts.getRoot();
}

Region City::getRegion() const{
    return this->region;
}