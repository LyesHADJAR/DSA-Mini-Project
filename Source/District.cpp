#include <utility>

#include"../Headers/District.h"

size_t District::district_hash(const std::string &district_name) {
    size_t hashValue = 0;

    for (char ch: district_name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

//  double District::generateDidtrictId() const  {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<int> dis(100, 999);

//     return (getCity_ID()*1000)+dis(gen);
// }

District::District(const string &District_Name, double spendBudget, const City &c) : spendBudget(spendBudget) {
    DistrictID = c.getCityID() + district_hash(District_Name) * 1000;
    setDistrict_Name(District_Name);
}

District::~District() {
    HouseHold_Tree.destroyTree();
}

size_t District::getDistrictID() const {
    return DistrictID;
}

string District::getDistrict_Name() const {
    return District_Name;
}

void District::setDistrict_Name(string DistrictName) {
    this->District_Name = std::move(DistrictName);
}

void District::addHouseHold(HouseHold &HouseHold) {
    HouseHold_Tree.insert(HouseHold);
}

void District::removeHouseHold(double HouseHold) {
    HouseHold_Tree.remove(HouseHold);
}

void District::updateHouseHold(const HouseHold &Newvalue, double HouseHold) {
    HouseHold_Tree.update(Newvalue, HouseHold);
}

HouseHold *District::searchHouseHold(size_t HouseHold_ID) {
    return HouseHold_Tree.search(HouseHold_ID);
}


double District::getDistrictConsumption() const {
    double totalConsumption = 0;
    inOrderTraversalForConsumption(HouseHold_Tree.getRoot(), totalConsumption);
    return totalConsumption;
}

void District::inOrderTraversalForConsumption(BSTNode *currentNode, double &totalConsumption) const {
    BSTNode *temp = currentNode;
    if (currentNode != nullptr) {
        inOrderTraversalForConsumption(temp->left, totalConsumption);
        totalConsumption += temp->data.getTotalConsumption();
        inOrderTraversalForConsumption(currentNode->right, totalConsumption);
    }
}

double District::getDistrictProduction() const {
    double totalProduction = 0;
    inOrderTraversalForProduction(HouseHold_Tree.getRoot(), totalProduction);
    return totalProduction;
}

void District::inOrderTraversalForProduction(BSTNode *currentNode, double &totalProduction) const {
    BSTNode *temp = currentNode;
    if (currentNode != nullptr) {
        inOrderTraversalForProduction(currentNode->left, totalProduction);
        totalProduction += temp->data.getTotalProduction();
        inOrderTraversalForProduction(currentNode->right, totalProduction);
    }
}

