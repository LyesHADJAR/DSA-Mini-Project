#include "district.h"

District::District(const string& name="", City& c) : districtName(name), city(c) {
    c.addDistrict(*this);
}

void District::addHouseholder(const Household& customer) {
    districtHouseholders.insert(customer);
}

void District::removeHouseholder(const Household& customer) {
    districtHouseholders.remove(customer);
}

BinarySearchTree<Household>::BinaryNode* District::findHouseholder(const Household & customer) {
    return districtHouseholders.findNode(customer);
};

float District::computeDistrictPerformance(BinarySearchTree<Household>::BinaryNode* households)const {
    return households->element.getElectricityData().getYearlyBill() + households->left->element.getElectricityData().getYearlyBill() + households->right->element.getElectricityData().getYearlyBill();
}