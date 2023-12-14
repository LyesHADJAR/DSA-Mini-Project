#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include"ElectricityData.h"
#include"Billing.h"
#include<vector>
#include <cmath>

class HouseHold {
    private:
        string Account_Holder_Name;
        string  householdID;
        string districtID;
        int Family_Members;
        vector<int> Family_Members_Ages ;
        string Address ;
        bool Is_Prize_Winner=false ;
        Electricity_Data HouseHold_Electricity_Data ;
        static size_t nextID;

    public:
        HouseHold( string ,int ,vector<int>, string, string );
        HouseHold(string);
        string getAccountHolderName() const;
        string getIDNumber() const;
        int getFamilyMembers() const;
        vector<int> getFamilyMembersAges() const;
        string getAddress() const;
        bool getIsPrizeWinner() const;
        Electricity_Data getHouseHoldElectricityData() const;
        void setAccountHolderName(string);
        void setFamilyMembers(int);
        void setFamilyMembersAges(vector<int>);
        void setAddress(string);
        void setIsPrizeWinner(bool);
        void setID();


        void addElectricityData(const Date& , double , double) ;

    // Get consumption and production data for a specific date
    pair<double, double> getElectricityData(const Date& date) ;

    // Get total consumption for all dates
    double getTotalConsumption() const ;

    // Get total production for all dates
    double getTotalProduction() const ;

    // Get the difference between total production and total consumption
    double getProductionConsumptionDifference() const ;

    double monthlyConsumption(int year, int month) const ;
    double monthlyProduction(int year, int month) const ;
    

    double yearlyProduction(int year) const;
    double yearlyConsumption(int year) const;

    std::vector<std::pair<Date, std::pair<double, double>>> get_data_in_range(const Date& start_date, const Date& end_date) const;

    // Retrieve consumption data for a specific month
    std::vector<std::pair<Date, double>> get_consumption_in_month(int year, int month) const;

    // Retrieve production data for a specific month
    std::vector<std::pair<Date, double>> get_production_in_month(int year, int month) const;

    // Retrieve consumption data for a specific year
    std::vector<std::pair<Date, double>> get_consumption_in_year(int year) const;

    // Retrieve production data for a specific year
    std::vector<std::pair<Date, double>> get_production_in_year(int year) const;




    bool operator<(const HouseHold& other) const {
        return this->householdID < other.householdID;
    }
    bool operator>(const HouseHold& other) const {
        return this->householdID > other.householdID;
    }
    bool operator==(const HouseHold& other) const {
        return this->householdID == other.householdID;
    }

};

#endif