#include "country.h"

Country::Country(const string& name){
    setCountryName(name);
}

void Country:: addRegion(const Region& NewRegion) {
    countryRegions.insert(NewRegion);
    //sortDepartmentsByBudget();
}

string Country::getCountryName()const {
    return countryName; 
}
void Country::setCountryName(string Country){
    countryName=Country;
}

BinarySearchTree<Region>::BinaryNode* Country::findRegion(const Region& RegionName) {
    
    return countryRegions.findNode(RegionName);
        
}

void Country::addDepartment(Department& dep) {
    countryDepartments.insert(dep);
}

void Country::findTop10(BinarySearchTree<Department>::BinaryNode* root, vector<Department> vect, int count)const {
     if (root == nullptr || count >= 10) return;
    findTop10(root->right, vect, count);

    if (count < 10) {
        vect.push_back(root->element);
        count++;
    }
    findTop10(root->left, vect, count);
}

void Country::findBottom10(BinarySearchTree<Department>::BinaryNode* root, vector<Department> vect, int count)const {
     if (root == nullptr || count >= 10) return;
    findBottom10(root->left, vect, count);

    if (count < 10) {
        vect.push_back(root->element);
        count++;
    }
    findBottom10(root->right, vect, count);
}

void Country::updateBudgets(){
    for(int i = 0; i < 9; i++){
        top10[i].increaseBudget(10);
        bottom10[i].decreaseBudget(10);
    }
    top10[9].increaseBudget(15);
    bottom10[9].decreaseBudget(15);
}