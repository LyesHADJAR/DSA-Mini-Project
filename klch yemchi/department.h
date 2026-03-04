#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <unordered_map>
#include "city.h"

using namespace std;

class City;

class HouseHold;

class Department {
private:
    string name;
    string cityId = "0";
    float budget, totalIncome{};
    float amountSpent;
    unordered_map<int, long double> performance;
    int ranking;
    City *depCity;
    string departmentID;

public:
    explicit Department(const string & = "", City * = nullptr);

    string getName() const;

    float getBudget() const;

    long double getPerformance(int);

    int getRanking() const;

    float getAmountSpent() const;

    string getCityID() const;

    void setID();

    string getID() const;

    void setDepartmentName(const string &);

    long double yearlyPerformance(int);

    void computePerformance();

    void updateRanking(int);

    void updateAmountSpent(float);

    void increaseBudget(float);

    void decreaseBudget(float);

    void resetBudget();

    friend ostream &operator<<(ostream &, const Department &);

    void displayDepartmentInfo() const;

    void setBudget(const float &);

    void setAmountSpent(const float &);

    void setRanking(const float &);

    // bool operator<(Department&);
    HouseHold *departmentCandidate(int, int, HouseHold * = nullptr);

    nlohmann::json departmentToJson() const;

    static Department departmentFromJson(const nlohmann::json &jsonFile);
};

#endif
