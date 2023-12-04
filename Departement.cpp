#include <iostream>
#include <string>

class Department {
private:
    std::string name;
    int departementId;
    float budget;
    float amountSpent;
    float performance;
    int ranking;

public:
    explicit Department(const std::string &deptName, int ID) {
        departementId = ID;
        name = deptName;
        budget = 10000000;
        amountSpent = 0;
        performance = 0; //THE SUM OF BILLS OF THE CITY OVER A YEAR
        ranking = 0; //INVALID VALUE IT NEEDS TO BE SET LATER
    }

    // Getter functions
    [[nodiscard]] std::string getName() const {
        return name;
    }

    [[nodiscard]] float getBudget() const {
        return budget;
    }

    [[nodiscard]] float getPerformance() const {
        return performance;
    }

    [[nodiscard]] int getRanking() const {
        return ranking;
    }

    [[nodiscard]] float getAmountSpent() const {
        return amountSpent;
    }

    [[nodiscard]] int geID() const {
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

    void displayDepartmentInfo() const {
        std::cout << "<================================== DEPARTMENT INFO ==================================> " << std::endl;
        std::cout << "Department Name: " << name << std::endl;
        std::cout << "Budget: " << budget << " Dinar" << std::endl;
        std::cout << "Performance: " << performance << std::endl;
    }
};
