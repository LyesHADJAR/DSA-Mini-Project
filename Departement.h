#include <iostream>
#include <string>
using namespace std;

class Department {
private:
    string name;
    int departementId;
    float budget;
    float amountSpent;
    float performance;
    int ranking;

public:
    explicit Department(const string &deptName="NoName", int ID=0) {
        departementId = ID;
        name = deptName;
        budget = 10000000;
        amountSpent = 0;#include <iostream>
#include <string>

class Department {
private:
    std::string name;
    int departmentId;
    float budget;
    float amountSpent;
    float performance;
    int ranking;

public:
    explicit Department(const std::string& deptName = "NoName", int ID = 0) {
        departmentId = ID;
        name = deptName;
        budget = 10000000;
        amountSpent = 0;
        performance = 0; // THE SUM OF BILLS OF THE CITY OVER A YEAR
        ranking = 0;     // INVALID VALUE IT NEEDS TO BE SET LATER
    }

    // Getter functions
    std::string getName() const {
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

    void setDepartmentName(const std::string& Name) {
        name = Name;
    }

    void setDepartmentID(int ID) {
        departmentId = ID;
    }

    void updatePerformance(float newPerformance) {
        if (newPerformance >= 0) {
            performance = newPerformance; // THE FUNCTION IS THE SUM OF THE FACTURES IN A GIVEN DAY
        } else {
            std::cerr << "Error: Performance cannot be negative." << std::endl;
        }
    }

    void updateRanking(int newRank) {
        ranking = newRank;
    }

    void updateAmountSpent(float spending) {
        if (spending >= 0) {
            amountSpent += spending;
        } else {
            std::cerr << "Error: Amount spent cannot be negative." << std::endl;
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
            std::cerr << "Error: Budget cannot go negative." << std::endl;
        }
    }

    void resetBudget() {
        budget = 10000000;
    }

    // Overloaded Output Operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Department& dept) {
        os << "<================================== DEPARTMENT INFO ==================================> " << std::endl;
        os << "Department Name: " << dept.name << std::endl;
        os << "Department ID: " << dept.departmentId << std::endl;
        os << "Budget: " << dept.budget << " Dinar" << std::endl;
        os << "Performance: " << dept.performance << std::endl;
        os << "Amount Spent: " << dept.amountSpent << std::endl;
        os << "Ranking: " << dept.ranking << std::endl;
        return os;
    }

    void displayDepartmentInfo() const {
        std::cout << *this;
    }
};
        performance = 0; //THE SUM OF BILLS OF THE CITY OVER A YEAR
        ranking = 0; //INVALID VALUE IT NEEDS TO BE SET LATER
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

     int geID() const {
        return departementId;
    }

    void updatePerformance(float newPerformance) {
        performance = newPerformance; // THE FUNCTION IS THE SUM OF THE FACTURES IN A GIVEN DAY
    }

    void updateRanking(int newRank) {
        ranking = newRank;
    }

    void updateAmountSpent(float spending) {
        amountSpent += spending;
    }

    void increaseBudget(float performanceIncreasePercentage) {
        budget += static_cast<float>(budget * (performanceIncreasePercentage / 100));
    }

    void decreaseBudget(float performanceDecreasePercentage) {
        budget -= static_cast<float>(budget * (performanceDecreasePercentage / 100));
    }
    void setDepartmentName(string Name){
        name=Name;
    }

    void displayDepartmentInfo() const {
        cout << "<================================== DEPARTMENT INFO ==================================> " << endl;
        cout << "Department Name: " << name << endl;
        cout << "Budget: " << budget << " Dinar" << endl;
        cout << "Performance: " << performance << endl;
    }
};
