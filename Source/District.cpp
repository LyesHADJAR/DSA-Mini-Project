#include"../Headers/District.h"


size_t District::nextID = 0;
//  double District::generateDidtrictId() const  {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<int> dis(100, 999);
 
//     return (getCity_ID()*1000)+dis(gen);
// }
District::District(string District_Name) {
    setDistrict_Name(District_Name);
    setDistrict_ID();
}
    District::~District(){
        HouseHold_Tree.destroyTree();
    }
    double District::getDistrict_ID()const  {
        return District_ID;
    }
    
    string District::getDistrict_Name() const {
        return District_Name;
    }
    void District::setDistrict_ID() {
        District_ID= ++nextID;
    }
    void District::setDistrict_Name(string District_Name) {
        this->District_Name=District_Name;
    }
    void District::addHouseHold(HouseHold &HouseHold) {
    HouseHold_Tree.insert(HouseHold);
    }
    void District::removeHouseHold(double HouseHold) {
        HouseHold_Tree.remove(HouseHold);
    }
    void District::updateHouseHold(const HouseHold& Newvalue,double HouseHold) {
        HouseHold_Tree.update(Newvalue,HouseHold);
    }
    HouseHold* District::searchHouseHold(double HouseHold_ID) {
        return HouseHold_Tree.search(HouseHold_ID);
    }
    
    
    double District::getDistrictConsumption() const {
    double totalConsumption = 0;
    inOrderTraversalForConsumption(HouseHold_Tree.getRoot(), totalConsumption);
    return totalConsumption;
    }

void District::inOrderTraversalForConsumption(BSTNode * currentNode, double& totalConsumption) const {
    BSTNode * temp = currentNode;
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

void District::inOrderTraversalForProduction(BSTNode* currentNode, double& totalProduction) const {
    BSTNode * temp = currentNode;
    if (currentNode != nullptr) {
        inOrderTraversalForProduction(currentNode->left, totalProduction);
        totalProduction += temp->data.getTotalProduction();
        inOrderTraversalForProduction(currentNode->right, totalProduction);
    }
}

    double District::spendBudget()const  {
        return getDistrictConsumption()*5-getDistrictProduction()*3;
    }

