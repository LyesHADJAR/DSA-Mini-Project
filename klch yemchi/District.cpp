#include"District.h"
#include <utility>

District::District(const string &District_Name, string ID, City *c) : city(c) {
    setDistrict_Name(District_Name);
    cityID = std::move(ID);
    isHouseholdIDUsed.resize(10000000);
    for (auto &&i: isHouseholdIDUsed) i = 0;
    if (!District_Name.empty()) setDistrict_ID();
}

District::~District() {
    HouseHold_Tree.destroyTree();
}

string District::getDistrict_ID() const {
    return District_ID;
}

string District::getDistrict_Name() const {
    return District_Name;
}

void District::setDistrict_ID() {
    size_t newID = city->getNextID();
    District_ID = cityID;
    if (newID / 10 == 0) District_ID += "00" + to_string(newID);
    else if (newID / 100 == 0) District_ID += "0" + to_string(newID);
    else District_ID += to_string(newID);
    city->incrementNextID();
    city->addDistrict(this);
}

void District::setDistrict_Name(string DistrictName) {
    this->District_Name = DistrictName;
}

void District::addHouseHold(const HouseHold &HouseHold) {
    // cout<<HouseHold.getAccountHolderName()<<"  "<<getDistrict_Name()<<endl;
    HouseHold_Tree.insert(HouseHold);
}

void District::removeHouseHold(double HouseHold) {
    HouseHold_Tree.remove(HouseHold);
}

void District::updateHouseHold(const HouseHold &Newvalue, double HouseHold) {
    HouseHold_Tree.update(Newvalue, HouseHold);
}

HouseHold *District::searchHouseHold(string HouseHold_ID) {
    return HouseHold_Tree.search(std::move(HouseHold_ID));
}

double District::getDistrictConsumption() {
    double totalConsumption = 0;
    inOrderTraversalForConsumption(HouseHold_Tree.getRoot(), totalConsumption);
    return totalConsumption;
}

void District::inOrderTraversalForConsumption(BSTNode<HouseHold> *currentNode, double &totalConsumption) {
    BSTNode<HouseHold> *temp = currentNode;
    if (currentNode != nullptr) {
        inOrderTraversalForConsumption(temp->left, totalConsumption);
        totalConsumption += temp->data.getTotalConsumption();
        inOrderTraversalForConsumption(currentNode->right, totalConsumption);
    }
}

double District::getDistrictProduction() {
    double totalProduction = 0;
    inOrderTraversalForProduction(HouseHold_Tree.getRoot(), totalProduction);
    return totalProduction;
}

void District::inOrderTraversalForProduction(BSTNode<HouseHold> *currentNode, double &totalProduction) {
    BSTNode<HouseHold> *temp = currentNode;
    if (currentNode != nullptr) {
        inOrderTraversalForProduction(currentNode->left, totalProduction);
        totalProduction += temp->data.getTotalProduction();
        inOrderTraversalForProduction(currentNode->right, totalProduction);
    }
}

double District::amountSpent() {
    return getDistrictConsumption() * 5 - getDistrictProduction() * 3;
}

long double District::districtYearlyBill(int year) {
    // cout<<District_ID<<"   "<<5*getDistrictConsumption()-3*getDistrictProduction()<<endl;
    return 5 * getDistrictConsumption() - 3 * getDistrictProduction();
}

bool District::isIDUsed(int id) {
    if (isHouseholdIDUsed[id]) return true;
    else {
        isHouseholdIDUsed[id] = true;
        return false;
    }
}

BSTNode<HouseHold> *
District::districtCandidateHelper(int year, int month, BSTNode<HouseHold> *root, BSTNode<HouseHold> *max) {
    if (root == NULL) {
        return max; // Return the maximum found so far
    }

    // Check if the current node has greater production than the current max
    if ((root->data).getProductionInRange(year, 1, 1, year, month, 31) >
        (max->data).getProductionInRange(year, 1, 1, year, month, 31)) {
        max = root;
    }

    // Search left and right subtrees for the maximum
    BSTNode<HouseHold> *leftMax = districtCandidateHelper(year, month, root->left, max);
    BSTNode<HouseHold> *rightMax = districtCandidateHelper(year, month, root->right, max);

    // Compare the max of left subtree with the max of right subtree
    if ((leftMax->data).getProductionInRange(year, 1, 1, year, month, 31) >
        (rightMax->data).getProductionInRange(year, 1, 1, year, month, 31)) {
        max = leftMax;
    } else {
        max = rightMax;
    }

    return max;
}

BSTNode<HouseHold> *District::getRoot() const {
    return HouseHold_Tree.getRoot();
}

HouseHold *District::districtCandidate(int year, int month, BSTNode<HouseHold> *root, BSTNode<HouseHold> *max) {
    return &(districtCandidateHelper(year, month, root, max)->data);
}

nlohmann::json District::DistrictToJson() const {
    nlohmann::json json;

    json["District_ID"] = District_ID;
    json["District_Name"] = District_Name;

    std::vector<nlohmann::json> householdsJson;
    for (const auto &household: HouseHold_Tree.inOrderTraversal()) {
        householdsJson.push_back(household.HouseHoldToJson());
    }

    json["Households"] = householdsJson;

    return json;
}

District District::DistrictFromJson(const nlohmann::json &jsonData) {
    if (!jsonData.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }

    District district(
            jsonData["District_Name"].get<std::string>(),
            jsonData["District_ID"].get<std::string>(),
            nullptr
    );

    if (jsonData.find("Households") != jsonData.end() && jsonData["Households"].is_array()) {
        for (const auto &householdJson: jsonData["Households"]) {
            HouseHold  newHouseHold(householdJson["Family_Members_Ages"], householdJson["Account_Holder_Name"], householdJson["Family_Members"], householdJson["Address"], householdJson["householdID"], &district);
            district.addHouseHold(newHouseHold);
        }
    }

    return district;
}
