#include <iostream>
#include "city.h"
using namespace std;

class Department {
private:
    string name;
    int departmentId;
    float budget, totalIncome;
    float amountSpent;
    float performance;
    int ranking;
    City depCity;

public:
    Department(const string& deptName = "NoName", int ID = 0, City& c): depCity(c){
        departmentId = ID;
        name = deptName;
        budget = 10000000;
        amountSpent = 0;
        performance = 0; // THE SUM OF BILLS OF THE CITY OVER A YEAR
        ranking = 0;     // INVALID VALUE IT NEEDS TO BE SET LATER
        depCity.getRegion().getCountry().addDepartment(*this);
    }

    // Getter functions
    string getName() const {
        return name;
    }

    float getBudget() const {
        return budget;
    }

    float getPerformance() const {
        return performance;
    }

    int getRanking() const {
        return ranking;
    }

    float getAmountSpent() const {
        return amountSpent;
    }

    int getID() const {
        return departmentId;
    }

    // Setter methods with validation

    void setDepartmentName(const string& Name) {
        name = Name;
    }

    void setDepartmentID(int ID) {
        departmentId = ID;
    }

    void updatePerformance(float newPerformance) {
        if (newPerformance >= 0) {
            performance = newPerformance; // THE FUNCTION IS THE SUM OF THE FACTURES IN A GIVEN DAY
        } else {
            cerr << "Error: Performance cannot be negative." << endl;
        }
    }

    void computePerformance() {
       updatePerformance(depCity.computeCityPerformance(depCity.getRoot()));
    }

    void updateRanking(int newRank) {
        ranking = newRank;
    }

    void updateAmountSpent(float spending) {
        if (spending >= 0) {
            amountSpent += spending;
        } else {
            cerr << "Error: Amount spent cannot be negative." << endl;
        }
    }

    void increaseBudget(float performanceIncreasePercentage) {
        budget += static_cast<float>(budget * (performanceIncreasePercentage / 100));
    }

    void decreaseBudget(float performanceDecreasePercentage) {
        float decreaseAmount = static_cast<float>(budget * (performanceDecreasePercentage / 100));
        if (budget - decreaseAmount >= 0) {
            budget -= decreaseAmount;
        } else {
            cerr << "Error: Budget cannot go negative." << endl;
        }
    }

    void resetBudget() {
        budget = 10000000;
    }

    // Overloaded Output Operator for easy printing
    friend ostream& operator<<(ostream& os, const Department& dept) {
        os << "<================================== DEPARTMENT INFO ==================================> " << endl;
        os << "Department Name: " << dept.name << endl;
        os << "Department ID: " << dept.departmentId << endl;
        os << "Budget: " << dept.budget << " Dinar" << endl;
        os << "Performance: " << dept.performance << endl;
        os << "Amount Spent: " << dept.amountSpent << endl;
        os << "Ranking: " << dept.ranking << endl;
        return os;
    }

    void displayDepartmentInfo() const {
        cout << *this;
    }

    bool operator< (const Department& dep)const {
        return departmentId < dep.departmentId;
    }
};