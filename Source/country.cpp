#include "country.h"

Country::Country(const string& name){
    setCountryName(name);
}

void Country:: addRegion(const Region& newRegion) {
    countryRegions[newRegion.getId()]= newRegion;
    regionIndexMap[newRegion.getRegionName()] = newRegion.getId();
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
    countryDepartments[dep.getID()]= dep;
    departmentIndexMap[dep.getName()] = dep.getID();
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

// void Country::findTop10(BinarySearchTree<Department>::BinaryNode* root, vector<Department> vect, int count)const {
//      if (root == nullptr || count >= 10) return;
//     findTop10(root->right, vect, count);

//     if (count < 10) {
//         vect.push_back(root->element);
//         count++;
//     }
//     findTop10(root->left, vect, count);
// }

// void Country::findBottom10(BinarySearchTree<Department>::BinaryNode* root, vector<Department> vect, int count)const {
//      if (root == nullptr || count >= 10) return;
//     findBottom10(root->left, vect, count);

//     if (count < 10) {
//         vect.push_back(root->element);
//         count++;
//     }
//     findBottom10(root->right, vect, count);
// }

// void Country::updateBudgets(){
//     for(int i = 0; i < 9; i++){
//         top10[i].increaseBudget(10);
//         bottom10[i].decreaseBudget(10);
//     }
//     top10[9].increaseBudget(15);
//     bottom10[9].decreaseBudget(15);
// }