#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "Date.h"

class Department {
private:
    std::string cityName;
    static int city_hash(const std::string&);
    unsigned int departementID = city_hash(cityName);
    int departmentID;
    float budget;
    float amountSpent;
    float performance;
    int ranking;

public:

    // Big five
    explicit Department(const std::string&);
    ~Department();
    Department(Department&&) noexcept ;
    Department& operator=(const Department&);
    Department& operator=(Department&&) noexcept ;

    // Getters
    int getDepartmentID() const;
    std::string getName() const;
    float getBudget() const;
    float getPerformance() const;
    int getRanking() const;
    float getAmountSpent() const;

    // Setters
    void setDepartmentName(const std::string& Name);
    void setDepartmentID(int ID);
    void updatePerformance(float newPerformance);
    void updateRanking(int newRank);
    void updateAmountSpent(float spending);

    // Budget
    void increaseBudget(float performanceIncreasePercentage);
    void decreaseBudget(float performanceDecreasePercentage);

};

