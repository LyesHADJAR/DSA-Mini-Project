#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
using namespace std;
#include "city.h"

class Department {
private:
    string name;
    size_t departmentID;
    float budget, totalIncome;
    float amountSpent;
    float performance;
    int ranking;
    City depCity;
    static size_t nextID;

public:
    Department(const string&, City&);

    string getName() const;
    float getBudget() const;
    float getPerformance() const;
    int getRanking() const;
    float getAmountSpent() const;
    size_t getDepID() const;

    void setDepartmentName(const string&);
    void updatePerformance(float);
    // void computePerformance();
    void updateRanking(int);
    void updateAmountSpent(float);
    void increaseBudget(float);
    void decreaseBudget(float);
    void resetBudget();

    friend ostream& operator<<(ostream&, const Department& );
    void displayDepartmentInfo() const;
//     bool operator< (const Department&) const;
//     bool operator<= (const Department&) const;
//     bool operator> (const Department&) const;
//     bool operator>= (const Department& ) const;
//     bool operator== (const Department&) const;
//     bool operator!= (const Department&) const;
};

#endif
