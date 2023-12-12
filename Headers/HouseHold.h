#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include"ElectricityData.h"
#include"Billing.h"
#include "District.h"
#include<vector>

class HouseHold {
private:
    string Account_Holder_Name;
    size_t householdID{};
    int Family_Members{};
    vector<int> Family_Members_Ages;
    string Address;
    District district;
    bool Is_Prize_Winner = false;
    Electricity_Data HouseHold_Electricity_Data;

    static size_t hash_household(const string &);

public:
    HouseHold(const string &Customer_Name, int Number_Memebers, const vector<int> &Ages, const string &Customer_Address,
              const District& d);
    HouseHold();

    string getAccountHolderName() const;

    size_t getIDNumber() const;

    int getFamilyMembers() const;

    vector<int> getFamilyMembersAges() const;

    string getAddress() const;

    bool getIsPrizeWinner() const;

    Electricity_Data getHouseHoldElectricityData() const;

    void setAccountHolderName(string);

    void setFamilyMembers(int);

    void setFamilyMembersAges(vector<int>);

    void setAddress(const string &);

    void setIsPrizeWinner(bool);

    // friend double generateCustomerID();
    void addElectricityData(const Date &, double, double);

    // Get consumption and production data for a specific date
    pair<double, double> getElectricityData(const Date &date);

    // Get total consumption for all dates
    double getTotalConsumption() const;

    // Get total production for all dates
    double getTotalProduction() const;

    // Get the difference between total production and total consumption
    double getProductionConsumptionDifference() const;

    double monthlyConsumption(int year, int month) const;

    double monthlyProduction(int year, int month) const;

    bool operator<(const HouseHold &other) const {
        return this->householdID < other.householdID;
    }

    bool operator>(const HouseHold &other) const {
        return this->householdID > other.householdID;
    }

    bool operator==(const HouseHold &other) const {
        return this->householdID == other.householdID;
    }

};

#endif