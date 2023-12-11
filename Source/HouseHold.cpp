#include"../Headers/HouseHold.h"
#include<random>

// Function to generate a random customer ID
//     double generateCustomerID() {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<int> dis(10000000, 99999999);
//     return dis(gen);
// }
    double HouseHold::nextID = 0;

    HouseHold::HouseHold( string Customer_Name ,int Number_Memebers ,vector<int>Ages, string Customer_Address ) {
        setAccountHolderName(Customer_Name);
    }

    HouseHold::HouseHold() {
        ID_Number = setID();
        setAccountHolderName("Unknown");
        setFamilyMembers(0);
        setFamilyMembersAges(vector<int>{});
        setAddress("unkown");
    }

    double HouseHold::setID() {
        ID_Number = ++nextID;
    }
    string HouseHold::getAccountHolderName() const 
        {
            return Account_Holder_Name;
        }
        double HouseHold::getIDNumber() const {
            return ID_Number;
        }
        int HouseHold::getFamilyMembers() const {
            return Family_Members;
        }
        vector<int> HouseHold::getFamilyMembersAges() const {
            return Family_Members_Ages;
        }
        string HouseHold::getAddress() const {
            return Address;
        }
        bool HouseHold::getIsPrizeWinner() const {
            return Is_Prize_Winner;
        }
        void HouseHold::setAccountHolderName(string Customer_Name) {
            if (Customer_Name.empty()) {
                throw std::invalid_argument("Invalid Customer Name");
            }
            // Check if all characters in the name are letters or spaces
            for (char ch : Customer_Name) {
                if (!std::isalpha(ch) && !std::isspace(ch)) {
                    throw std::invalid_argument("Invalid Customer Name (all characters in the name Must be letters or spaces)");
                    }
                }

                // Check if the name does not start or end with a space
                if (std::isspace(Customer_Name.front()) ) {
                throw std::invalid_argument("Invalid Customer Name (Customer Name does not start with a space)");
                }
            Account_Holder_Name=Customer_Name;
        }
        
        void HouseHold::setFamilyMembers(int Number_Memebers) {
            if (Number_Memebers < 0) {
                throw std::invalid_argument("Invalid Number of Members");
                }
                Family_Members = Number_Memebers;
        }
        void HouseHold::setFamilyMembersAges(vector<int> Ages) {
            if(getFamilyMembers()!=Ages.size())
            {
                throw std::invalid_argument("Invalid Number of Members");
                }
            for (int element : Ages) {
                if (element < 0) {
                    throw std::invalid_argument("Invalid Age");
                    }
                    Family_Members_Ages = Ages;
                }
        }
        void HouseHold::setAddress(string Customer_Address) {
            if (Customer_Address.empty()) {
                throw std::invalid_argument("Invalid Address");
                }
                Address=Customer_Address;
        }
        void HouseHold::setIsPrizeWinner(bool Value) {
            Is_Prize_Winner = Value;
        }


        void HouseHold::addElectricityData(const Date& New_Date , double Consumption , double Production)  {
            if (Consumption < 0 || Production < 0) {
                throw std::invalid_argument("Invalid Consumption or Production");
                }
                HouseHold_Electricity_Data.add_data(New_Date,Consumption,Production);
        }

    // Get consumption and production data for a specific date
    pair<double, double> HouseHold::getElectricityData(const Date& date)  {
        return HouseHold_Electricity_Data.get_data(date);
    }

    // Get total consumption for all dates
    double HouseHold::getTotalConsumption() const {
        return HouseHold_Electricity_Data.get_total_consumption();
    }

    // Get total production for all dates
    double HouseHold::getTotalProduction() const  {
        return HouseHold_Electricity_Data.get_total_production();
    }

    // Get the difference between total production and total consumption
    double HouseHold::getProductionConsumptionDifference() const {
        return HouseHold_Electricity_Data.get_production_consumption_difference();
    }
    double HouseHold::monthlyConsumption(int year ,int month ) const 
    {
        return HouseHold_Electricity_Data.monthlyConsumption(year,month);
    }
    double HouseHold::monthlyProduction(int year,int month)const {
        return HouseHold_Electricity_Data.monthlyProduction(year,month);
    }