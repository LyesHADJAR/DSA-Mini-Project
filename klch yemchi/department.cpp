#include "department.h"
#include "city.h"


Department::Department(const string &deptName, City *c) : depCity(c) {
    name = deptName;
    budget = 10000000;
    amountSpent = 0;
    ranking = 0;
    setID();
}

string Department::getName() const {
    return name;
}

float Department::getBudget() const {
    return budget;
}

long double Department::getPerformance(int year) {
    return yearlyPerformance(year);
}

int Department::getRanking() const {
    return ranking;
}

float Department::getAmountSpent() const {
    return amountSpent;
}

string Department::getCityID() const {
    return cityId;
}

void Department::setDepartmentName(const string &Name) {
    name = Name;
}

void Department::updateRanking(int newRank) {
    ranking = newRank;
}

void Department::updateAmountSpent(float spending) {
    if (spending >= 0) {
        amountSpent += spending;
    } else {
        cerr << "Error: Amount spent cannot be negative." << endl;
    }
}

void Department::increaseBudget(float performanceIncreasePercentage) {
    budget += static_cast<float>(budget * (performanceIncreasePercentage / 100));
}

void Department::decreaseBudget(float performanceDecreasePercentage) {
    float decreaseAmount = static_cast<float>(budget * (performanceDecreasePercentage / 100));
    if (budget - decreaseAmount >= 0) {
        budget -= decreaseAmount;
    } else {
        cerr << "Error: Budget cannot go negative." << endl;
    }
}

void Department::resetBudget() {
    budget = 10000000;
}

// Overloaded Output Operator for easy printing
ostream &operator<<(ostream &os, const Department &dept) {
    os << "<================================== DEPARTMENT INFO ==================================> " << endl;
    os << "Department Name: " << dept.name << endl;
    os << "Department ID: " << dept.cityId << endl;
    os << "Budget: " << dept.budget << " Dinar" << endl;
    os << "Amount Spent: " << dept.amountSpent << endl;
    os << "Ranking: " << dept.ranking << endl;
    return os;
}

void Department::displayDepartmentInfo() const {
    cout << *this;
}

long double Department::yearlyPerformance(int year) {
    performance[year] = depCity->cityYearlyBill(year);
    return performance[year];
}

string Department::getID() const {
    return departmentID;
}

void Department::setID() {
    departmentID = depCity->getID();
    depCity->getRegion()->getCountry()->addDepartment(this);
}

HouseHold *Department::departmentCandidate(int year, int month, HouseHold *max) {
    return depCity->cityCandidate(year, month, max);
}

void Department::setBudget(const float & b) {
    budget = b;
}

void Department::setAmountSpent(const float & a) {
    amountSpent = a;
}

void Department::setRanking(const float &r) {
    ranking = r;
}

nlohmann::json Department::departmentToJson() const {
    nlohmann::json jsonFile;

    jsonFile["Budget"] = budget;
    jsonFile["AmountSpent"] = amountSpent;
    jsonFile["Ranking"] = ranking;

    return jsonFile;
}

Department Department::departmentFromJson(const nlohmann::json &jsonData) {
    if (!jsonData.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }
    Department department(
            jsonData["Department_Name"].get<std::string>(),
            nullptr
    );
    return department;
}
