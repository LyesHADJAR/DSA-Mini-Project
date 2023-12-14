#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
using namespace std;
#include "city.h"

class Department {
private:
    string name;
    string departmentId;
    float budget, totalIncome;
    float amountSpent;
    unordered_map<int, long double> performance;
    int ranking;
    City* depCity;
    int currentYear;

public:
    Department(const string&, City*, int = 2023);

    string getName() const;
    float getBudget() const;
    long double getPerformance(int);
    int getRanking() const;
    float getAmountSpent() const;
    string getID() const;
    void setCurrentYear(int);

    void setDepartmentName(const string&);
    long double yearlyPerformance(int);
    // void computePerformance();
    void updateRanking(int);
    void updateAmountSpent(float);
    void increaseBudget(float);
    void decreaseBudget(float);
    void resetBudget();

    friend ostream& operator<<(ostream&, const Department& );
    void displayDepartmentInfo() const;
    bool operator<(Department&);
};

#endif
