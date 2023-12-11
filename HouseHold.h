#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include "ElectricityData.h"
#include "District.h"
#include "Date.h"
#include <vector>


class HouseHold {
    private:
        string Account_Holder_Name;
        static int household_hash(const std::string&);
        size_t ID_Number = household_hash(Account_Holder_Name);
        int Family_Members{};
        vector<int> Family_Members_Ages ;
        string Address ;
        bool Is_Prize_Winner=false ;
        Electricity_Data HouseHold_Electricity_Data ;

    public:
        HouseHold( string ,int ,const vector<int>&, const string& );
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
        void setAddress(string);
        void setIsPrizeWinner(bool);
        void addElectricityData(const Date& , double , double) ;

    // Get consumption and production data for a specific date
    pair<double, double> getElectricityData(const Date& date) ;

    // Get total consumption for all dates
    double getTotalConsumption() const ;

    // Get total production for all dates
    double getTotalProduction() const ;

    // Get the difference between total production and total consumption
    double getProductionConsumptionDifference() const ;
};

#endif