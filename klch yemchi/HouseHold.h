#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include "ElectricityData.h"
#include "District.h"
#include<vector>
#include <iostream>

using namespace std;

class District;

class HouseHold {
private:
    string Account_Holder_Name;
    string householdID;
    string districtID;
    int Family_Members{};
    vector<int> Family_Members_Ages;
    string Address;
    bool Is_Prize_Winner = false;
    Electricity_Data HouseHold_Electricity_Data;
    District *district{};

public:
    explicit HouseHold(vector<int> = {}, string = "", int = 0, string = "", string = "", District * = nullptr);

    explicit HouseHold(string);

    string getAccountHolderName() const;

    string getIDNumber() const;

    int getFamilyMembers() const;

    vector<int> getFamilyMembersAges() const;

    string getAddress() const;

    bool getIsPrizeWinner() const;

    // Electricity_Data getHouseHoldElectricityData() const;
    void setAccountHolderName(string);

    void setFamilyMembers(int);

    void setFamilyMembersAges(vector<int>);

    void setAddress(string);

    void setIsPrizeWinner(bool);

    void setID();

    long double householdYearlyBill(int year) const;

    void addElectricityData(const Date &, double, double);

    string getDistrict_ID();

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


    double yearlyProduction(int year) const;

    double yearlyConsumption(int year) const;

    vector<pair<Date, pair<double, double>>> get_data_in_range(int, int, int, int, int, int) const;

    vector<pair<Date, pair<double, double>>> getMonthlyData(int, int) const;

    vector<pair<Date, pair<double, double>>> getYearlyData(int) const;

    double getProductionInRange(int, int, int, int, int, int) const;

    double getConsumptionInRange(int, int, int, int, int, int) const;

    bool operator<(const HouseHold &other) const {
        return this->householdID < other.householdID;
    }

    bool operator>(const HouseHold &other) const {
        return this->householdID > other.householdID;
    }

    bool operator==(const HouseHold &other) const {
        return this->householdID == other.householdID;
    }

    // Write the data of a household into a .json file
    nlohmann::json HouseHoldToJson() const;

    // Get the data of a household into a .json file
    static HouseHold HouseHoldFromJson(const nlohmann::json &jsonData);

    void setDistrict(District *);
};

#endif
