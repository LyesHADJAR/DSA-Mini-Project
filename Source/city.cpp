#include "city.h"

size_t City::nextID = 0;

City::City(const string& newCity="", Region& reg):cityName{newCity}, region(reg), Department_Of_This_City(newCity,*this){
        reg.addCity(*this);
        setID();
}

void City:: setCityName(const string& city){
        cityName=city;
}

string City::getCityName()const {
            return cityName;
}

void City::addDistrict(const District & newDistrict) {
        citydistricts[newDistrict.getDistrict_ID()] = newDistrict;
        districtIndexMap[newDistrict.getDistrict_Name()] = newDistrict.getDistrict_ID();
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

// float City::computeCityPerformance(BinarySearchTree<District>::BinaryNode* districts)const {
//    return districts->element.computeDistrictPerformance(districts->element.getRoot())+ districts->left->element.computeDistrictPerformance(districts->left->element.getRoot()) + districts->right->element.computeDistrictPerformance(districts->right->element.getRoot());
// }

// BinarySearchTree<District>::BinaryNode* City:: getRoot() {
//         return Citydistricts.getRoot();
// }

Region City::getRegion() const{
    return this->region;
}

size_t City::getID()const {
        return cityID;
}

void City::setID() {
        cityID = ++nextID;
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