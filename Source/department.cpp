#include "department.h"

size_t Department::nextID = 0; 

Department::Department(const string& deptName, City& c) : depCity(c) {
    name = deptName;
    budget = 10000000;
    amountSpent = 0;
    performance = 0;
    ranking = 0;
    depCity.getRegion().getCountry().addDepartment(*this);
}

std::string Department::getName() const {
    return name;
}

float Department::getBudget() const {
    return budget;
}

float Department::getPerformance() const {
    return performance;
}

int Department::getRanking() const {
    return ranking;
}

float Department::getAmountSpent() const {
    return amountSpent;
}

int Department::getID() const {
    return departmentId;
}

void Department::setDepartmentName(const std::string& Name) {
    name = Name;
}

void Department::setDepartmentID() {
    departmentId = ++Department::nextID;
}

void Department::updatePerformance(float newPerformance) {
    if (newPerformance >= 0) {
        performance = newPerformance;
    } else {
        std::cerr << "Error: Performance cannot be negative." << std::endl;
    }
}

// void Department::computePerformance() {
//     updatePerformance(depCity.computeCityPerformance(depCity.getRoot()));
// }

void Department::updateRanking(int newRank) {
    ranking = newRank;
}

void Department::updateAmountSpent(float spending) {
    if (spending >= 0) {
        amountSpent += spending;
    } else {
        std::cerr << "Error: Amount spent cannot be negative." << std::endl;
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
        std::cerr << "Error: Budget cannot go negative." << std::endl;
    }
}

void Department::resetBudget() {
    budget = 10000000;
}

// Overloaded Output Operator for easy printing
std::ostream& operator<<(std::ostream& os, const Department& dept) {
    os << "<================================== DEPARTMENT INFO ==================================> " << std::endl;
    os << "Department Name: " << dept.name << std::endl;
    os << "Department ID: " << dept.departmentId << std::endl;
    os << "Budget: " << dept.budget << " Dinar" << std::endl;
    os << "Performance: " << dept.performance << std::endl;
    os << "Amount Spent: " << dept.amountSpent << std::endl;
    os << "Ranking: " << dept.ranking << std::endl;
    return os;
}

void Department::displayDepartmentInfo() const {
    std::cout << *this;
}

// bool Department::operator< (const Department& dep) const {
//     return departmentId < dep.departmentId;
// }

// bool Department::operator<= (const Department& dep) const {
//     return departmentId <= dep.departmentId;
// }
// bool Department::operator> (const Department& dep) const {
//     return departmentId > dep.departmentId;
// }

// bool Department::operator>= (const Department& dep) const {
//     return departmentId >= dep.departmentId;
// }
// bool Department::operator== (const Department& dep) const {
//     return departmentId == dep.departmentId;
// }

// bool Department::operator!= (const Department& dep) const {
//     return departmentId != dep.departmentId;
// }