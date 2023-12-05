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
        amountSpent = 0;
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
