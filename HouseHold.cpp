#include"HouseHold.h"
#include <utility>

int HouseHold::household_hash(const std::string &name) {
    int hashValue = 0;

    for (char ch: name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

HouseHold::HouseHold(string Customer_Name, int Number_Members = 0, const vector<int> &Ages = {},
                     const string &Customer_Address = "Unknown") {
    setAccountHolderName(std::move(Customer_Name));
}

string HouseHold::getAccountHolderName() const {
    return Account_Holder_Name;
}

size_t HouseHold::getIDNumber() const {
    return ID_Number;
}

int HouseHold::getFamilyMembers() const {
    return Family_Members;
}

vector<int> HouseHold::getFamilyMembersAges() const {
    return Family_Members_Ages;
}

string HouseHold::getAddress() const {
    return Address;
}

bool HouseHold::getIsPrizeWinner() const {
    return Is_Prize_Winner;
}

void HouseHold::setAccountHolderName(string Customer_Name) {
    if (Customer_Name.empty()) {
        throw std::invalid_argument("Invalid Customer Name");
    }
    // Check if all characters in the name are letters or spaces
    for (char ch: Customer_Name) {
        if (!std::isalpha(ch) && !std::isspace(ch)) {
            throw std::invalid_argument("Invalid Customer Name (all characters in the name Must be letters or spaces)");
        }
    }

    // Check if the name does not start or end with a space
    if (std::isspace(Customer_Name.front())) {
        throw std::invalid_argument("Invalid Customer Name (Customer Name does not start with a space)");
    }
    Account_Holder_Name = Customer_Name;
}

void HouseHold::setFamilyMembers(int) {

}

void HouseHold::setFamilyMembersAges(vector<int>) {

}

void HouseHold::setAddress(string) {

}

void HouseHold::setIsPrizeWinner(bool) {

}


void HouseHold::addElectricityData(const Date &, double, double) {

}

// Get consumption and production data for a specific date
pair<double, double> HouseHold::getElectricityData(const Date &date) {

}

// Get total consumption for all dates
double HouseHold::getTotalConsumption() const {

}

// Get total production for all dates
double HouseHold::getTotalProduction() const {

}

// Get the difference between total production and total consumption
double HouseHold::getProductionConsumptionDifference() const {

}
