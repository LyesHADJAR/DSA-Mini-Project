#include "household.h"

size_t Household::nextID = 0; 

Household::Household (District& dis, const string& fn, const string& ln): district(dis){
    dis.addHouseholder(*this);
    setFirstName(fn);
    setLastName(ln);
}

BinarySearchTree<electricityData>::BinaryNode* Household::getElectricityData()const {
    return householdElectricityData.getRoot();
}

void Household::addElectricityData(electricityData elData){
    householdElectricityData.insert(elData);
}

void Household::removeElectricityData(electricityData elData){
    householdElectricityData.remove(elData);
}

void Household::setId(){
    ID = ++nextID;
}

void Household::setFirstName(const string& name) {
    bool isValid = true;
    for (char c : name) {
        if (!isalpha(c)) {
                isValid = false;
                break;
        }
    }
    if (!name.empty() && isValid) {
            firstName = name;
    }
    else {
            cout << "Invalid first name. Please enter a valid name without numbers or special characters." << endl;
    }
}

void Household::setLastName(const string& name) {
    bool isValid = true;
    for (char c : name) {
        if (!isalpha(c)) {
                isValid = false;
                break;
        }
    }
    if (!name.empty() && isValid) {
            lastName = name;
    }
    else {
            cout << "Invalid last name. Please enter a valid name without numbers or special characters." << endl;
    }
}


const string& Household::getFirstName()const {
    return firstName;
}

const string& Household::getLastName()const {
    return lastName;
}