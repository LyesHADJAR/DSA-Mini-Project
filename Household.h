/*#ifndef HOUSEHOLD_H_INCLUDED
#define HOUSEHOLD_H_INCLUDED


---------------------------------INFORMATIONS ABOUT THE CUSTOMER---------------------------------
1.The Name Of Customer
2.The ID Of The Electricity Account Holder
3.The Number Of Family Members
4.There Ages
5.The Address (District,City,Region)


*/
/*
---------------------------------INFORMATIONS ABOUT THE DS USED IN THIS HEADER FILE---------------------------------
1.Pair is used to combine together two values that may be of different data types.(store tuples)
    in our case The pair is used to store the family members names as string  and ages as int,
    To acess the first element we just write Object_name.first and the same for the second Object_Name.second
2.vector
3.unordered_map



#include<iostream>
#include<vector>
#include<unordered_map> //For Hashing Reasons
#include<string>
#include <stdexcept>
#include<iomanip>
using namespace std ;


//Class HouseHold Is The class That Represent The Customer

class HouseHold {

    public:
        enum class BillingStatus {
        NoCharge,
        Payment,
        Credit
    };
    private:
        string Account_Holder_Name; //Customer_Name

        size_t ID_Number; // The ID Contains 10 Numbers

        vector<pair<string,int>> Family_Members_And_Ages;
        /*I Used Vector STL And Pair STL That Contains The name and the age of each
        family member to avoid using tow arrays and liked them after that 

        unordered_map<string,pair<size_t,size_t>> Electricity_Data;// Date -> {consumption, production}
        /*
        description:
        This Function used to store information about the electricity consumption and production for each date;
        1.string: The key type of the map. It represents the date on which the electricity data is recorded.
        2.pair<int, int>: The value type of the map. It is a pair of integers representing the consumption and production of electricity on a specific date.

        So, electricity_data is a map that allows you to associate each date with a pair of integers, where the first integer represents
         the consumption of electricity on that date, and the second integer represents the production of electricity on that date.
        This map is used to keep track of the electricity data over time for a particular household.
        

       //All The Information About The Customer Address
        struct Address {
            string Address;
            string District;
            string City;
            string Region;
        } Address_Info;


        //I will see What are These Variables For --> XXXXX

        double National_Prize_Energy; // Cumulative energy for national prize eligibility
        bool Is_Prize_Winner; // Whether the household won the national prize
        double billAmount;       // New member to store the calculated bill amount
        BillingStatus billingStatus; // New member to indicate the billing status
    public:
        explicit HouseHold(string Customer_Name,int Customer_Id,const vector<pair<string,int>>& Family_Memeber,string Customer_Address ,string Customer_District,string Customer_City,string Customer_Region):
        Account_Holder_Name(Customer_Name),ID_Number(Customer_Id),Family_Members_And_Ages(Family_Memeber),Address_Info({Customer_Address,Customer_District,Customer_City,Customer_Region}),Is_Prize_Winner(false),National_Prize_Energy(0){}

        void setFamilyMembers(const vector<pair<string,int>>&Family_Memeber)
        {
            Family_Members_And_Ages = Family_Memeber;
        }
        vector<pair<string, int>> getFamilyMembers() const {
            return Family_Members_And_Ages;
        }
        void setAddressInfo(const Address& Address_INFO) const{
            Address_Info.Address=Address_INFO.Address;
            Address_Info.City=Address_INFO.City;
            Address_Info.District=Address_INFO.District;
            Address_Info.Region=Address_INFO.Region;
        }
        Address getAddressInfo() const{
            return Address_Info;
        };
        void addElectricityData(string Date, size_t Consumption, size_t Production){
            // Check for valid date format (you may want to use a library for more comprehensive validation)
        if (Date.length() != 10 || Date[4] != '-' || Date[7] != '-') {
            throw invalid_argument("Invalid date format. Expected: YYYY-MM-DD");
        }

        // Check for non-negative consumption and production values
        if (Consumption < 0 || Production < 0) {
            throw invalid_argument("Consumption and production values must be non-negative.");
        }

        // electricity_data is an unordered_map with string keys (dates) and pair<int, int> values (consumption, production)
        Electricity_Data[Date] = make_pair(Consumption, Production);
        National_Prize_Energy += (Production > Consumption) ? Production - Consumption : 0;
        }
        unordered_map<string, pair<int, int>> getElectricityData(){
            return Electricity_Data;
        }
        void setNationalPrizeEnergy(double Energy){
            // Check for non-negative energy value
        if (Energy < 0) {
            throw invalid_argument("National prize energy must be non-negative.");
        }
            National_Prize_Energy = Energy;
        }
        double getNationalPrizeEnergy() const{
            return National_Prize_Energy;
        }
        void setIsPrizeWinner(bool winner){
            Is_Prize_Winner = winner;
        }
        bool getIsPrizeWinner() const {
            return Is_Prize_Winner;
        }
        int getTotalConsumption() const {
            double totalConsumption = 0;
            for (const auto& data : Electricity_Data) {
            totalConsumption += data.second.first; // Accessing consumption from the pair
        }
            return totalConsumption;
        }
        int getTotalProduction() const {
            double totalProduction = 0;
        for (const auto& data : Electricity_Data) {
            totalProduction += data.second.second;
        }
        return totalProduction;
        }

        void calculateBill() const {
            double netConsumption = getTotalConsumption() - getTotalProduction();

        if (netConsumption > 0) {
            // Customer consumed more than produced
            billAmount = netConsumption * 5.0; // Charge 5 DA per kilowatt hour consumed
            billingStatus = BillingStatus::Payment;
        } else if (netConsumption < 0) {
            // Customer produced more than consumed
            int netProduction = -netConsumption;
            billAmount = netProduction * 3.0; // Credit 3 DA per kilowatt hour injected
            billingStatus = BillingStatus::Credit;
        } else {
            // Net consumption is zero, no charge or credit
            billAmount = 0.0;
            billingStatus = BillingStatus::NoCharge;
        }
        }
        void checkNationalPrize() {
            if (National_Prize_Energy >= 1000) {
        setIsPrizeWinner(true);
    }
    else {
        setIsPrizeWinner(false);
    }
        }
        friend ostream& operator<<(ostream& os, const HouseHold& household){
            os << "\033[1;37;41m" << setw(50) << right << " HOUSEHOLD INFORMATION \033[0m\n\n";
        os << setw(25) << left << "Household Name: " << setw(25) << right << household.Account_Holder_Name << "\n";
        os << setw(25) << left << "ID: " << setw(25) << right << household.ID_Number << "\n";
        os << setw(25) << left << "Address: " << setw(25) << right << household.Address_Info.Address<< "\n";
        os << setw(25) << left << "District: " << setw(25) << right << household.Address_Info.District << "\n";
        os << setw(25) << left << "City: " << setw(25) << right << household.Address_Info.City << "\n";
        os << setw(25) << left << "Region: " << setw(25) << right << household.Address_Info.Region << "\n\n";

        os << "\033[1;37;41m" << setw(50) << right << " FAMILY MEMBERS \033[0m\n";
        for (const auto& member : household.Family_Members_And_Ages) {
            os << setw(25) << left << "Name: " << setw(25) << right << member.first;
            os << setw(25) << left << "Age: " << setw(25) << right << member.second << "\n";
        }

        os << "\n\033[1;37;41m" << setw(50) << right << " ELECTRICITY INFORMATION \033[0m\n";
        os << setw(25) << left << "Total Consumption: " << setw(25) << right << household.getTotalConsumption() << " kWh\n";
        os << setw(25) << left << "Total Production: " << setw(25) << right << household.getTotalProduction() << " kWh\n";
        os << setw(25) << left << "Current Bill: " << setw(25) << right << household.getBillAmount() << " Dinar\n";
        switch (household.getBillingStatus()) {
        case Household::BillingStatus::NoCharge:
            os << "No charge for this month.\n";
            break;
        case Household::BillingStatus::Payment:
            std::cout << "Your bill amount is " << household.getBillAmount() << " Dinar. Please make a payment.\n";
            // You may want to handle the payment accordingly
            break;
        case Household::BillingStatus::Credit:
            std::cout << "Congratulations! You have a credit of " << household.getBillAmount() << " Dinar.\n";
            // You may want to handle the credit accordingly (e.g., transfer money to the customer's account)
            break;
    }

        if (household.Is_Prize_Winner) {
            os << "\033[1;32mCongratulations! National Prize Winner.\033[0m\n";
        } else {
            os << "\033[1;31mNot eligible for the national prize this month.\033[0m\n";
        }

        os << "\n";

        return os;
        }
        friend istream& operator>>(istream& is, HouseHold& household) {
            cout << "Enter Household Name: ";
        getline(is, household.Account_Holder_Name);

        cout << "Enter Household ID: ";
        is >> household.ID_Number;

        cout << "Enter Address: ";
        getline(is, household.Address_Info.Address);

        cout << "Enter District: ";
        getline(is, household.Address_Info.District);

        cout << "Enter City: ";
        getline(is, household.Address_Info.City);

        cout << "Enter Region: ";
        getline(is, household.Address_Info.Region);

        cout << "Enter the number of family members: ";
        int numMembers;
        is >> numMembers;
        is.ignore(); // Clear the newline character from the buffer

        household.Family_Members_And_Ages.clear(); // Clear existing family members
        for (int i = 0; i < numMembers; ++i) {
            string name;
            int age;

            cout << "Enter Family Member " << i + 1 << " Name: ";
            getline(is, name);

            cout << "Enter Family Member " << i + 1 << " Age: ";
            is >> age;
            is.ignore(); // Clear the newline character from the buffer

            household.Family_Members_And_Ages.push_back(make_pair(name, age));
        }

        return is;
        }
        BillingStatus getBillingStatus() const {
            return billingStatus;
        }
        double getBillAmount() const {
            return billAmount;
        }
        void SetBillAmount(double Amount) {
            billAmount=Amount;
        }
        void SetBillStatus(const BillingStatus & value)
        {
            billingStatus=value;
        }

};


#endif // HOUSEHOLD_H_INCLUDED
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

class Household {
public:
    enum class BillingStatus {
        NoCharge,
        Payment,
        Credit
    };

private:
    string Account_Holder_Name;
    size_t ID_Number;
    vector<pair<string, int>> Family_Members_And_Ages;//ages and number
    unordered_map<string, pair<size_t, size_t>> Electricity_Data;
    struct Address {
        string Address;
        string District;
        string City;
        string Region;
    } Address_Info;

    double National_Prize_Energy;
    bool Is_Prize_Winner;
    double billAmount;
    BillingStatus billingStatus;

    

public:
    Household() :
        ID_Number(0),
        Is_Prize_Winner(false),
        National_Prize_Energy(0),
        billAmount(0.0),
        billingStatus(BillingStatus::NoCharge) {}

    explicit Household(string Customer_Name, int Customer_Id, const vector<pair<string, int>>& Family_Member,
                       string Customer_Address, string Customer_District, string Customer_City, string Customer_Region) :
        Account_Holder_Name(Customer_Name), ID_Number(Customer_Id), Family_Members_And_Ages(Family_Member),
        Address_Info({ Customer_Address, Customer_District, Customer_City, Customer_Region }), Is_Prize_Winner(false),
        National_Prize_Energy(0), billAmount(0), billingStatus(BillingStatus::NoCharge) {}

    void setFamilyMembers(const vector<pair<string, int>>& Family_Member) {
        Family_Members_And_Ages = Family_Member;
    }

    vector<pair<string, int>> getFamilyMembers() const {
        return Family_Members_And_Ages;
    }

    void setAddressInfo(const Address& Address_INFO) {
        Address_Info.Address = Address_INFO.Address;
        Address_Info.City = Address_INFO.City;
        Address_Info.District = Address_INFO.District;
        Address_Info.Region = Address_INFO.Region;
    }

    Address getAddressInfo() const {
        return Address_Info;
    };

    size_t getId () const 
    {
        return ID_Number;
    }

    void addElectricityData(string Date, size_t Consumption, size_t Production) {
        if (Date.length() != 10 || Date[4] != '-' || Date[7] != '-') {
            throw invalid_argument("Invalid date format. Expected: YYYY-MM-DD");
        }

        if (Consumption < 0 || Production < 0) {
            throw invalid_argument("Consumption and production values must be non-negative.");
        }

        Electricity_Data[Date] = make_pair(Consumption, Production);
        National_Prize_Energy += (Production > Consumption) ? Production - Consumption : 0;
    }

    unordered_map<string, pair<size_t, size_t>> getElectricityData() const {
        return Electricity_Data;
    }

    void setNationalPrizeEnergy(double Energy) {
        if (Energy < 0) {
            throw invalid_argument("National prize energy must be non-negative.");
        }
        National_Prize_Energy = Energy;
    }

    double getNationalPrizeEnergy() const {
        return National_Prize_Energy;
    }

    void setIsPrizeWinner(bool winner) {
        Is_Prize_Winner = winner;
    }

    bool getIsPrizeWinner() const {
        return Is_Prize_Winner;
    }

    size_t getTotalConsumption() const {
        size_t totalConsumption = 0;
        for (const auto& data : Electricity_Data) {
            totalConsumption += data.second.first;
        }
        return totalConsumption;
    }

    size_t getTotalProduction() const {
        size_t totalProduction = 0;
        for (const auto& data : Electricity_Data) {
            totalProduction += data.second.second;
        }
        return totalProduction;
    }

    void calculateBill() {
        int netConsumption = getTotalConsumption() - getTotalProduction();

        if (netConsumption > 0) {
            billAmount = netConsumption * 5.0;
            billingStatus = BillingStatus::Payment;
        } else if (netConsumption < 0) {
            billAmount = -netConsumption * 3.0;
            billingStatus = BillingStatus::Credit;
        } else {
            billAmount = 0.0;
            billingStatus = BillingStatus::NoCharge;
        }
    }

    void checkNationalPrize() {
        if (National_Prize_Energy >= 1000) {
            setIsPrizeWinner(true);
        } else {
            setIsPrizeWinner(false);
        }
    }

    friend ostream& operator<<(ostream& os, const Household& household) {
        os << "\033[1;37;41m" << setw(50) << right << " HOUSEHOLD INFORMATION \033[0m\n\n";
        os << setw(25) << left << "Household Name: " << setw(25) << right << household.Account_Holder_Name << "\n";
        os << setw(25) << left << "ID: " << setw(25) << right << household.ID_Number << "\n";
        os << setw(25) << left << "Address: " << setw(25) << right << household.Address_Info.Address << "\n";
        os << setw(25) << left << "District: " << setw(25) << right << household.Address_Info.District << "\n";
        os << setw(25) << left << "City: " << setw(25) << right << household.Address_Info.City << "\n";
        os << setw(25) << left << "Region: " << setw(25) << right << household.Address_Info.Region << "\n\n";

        os << "\033[1;37;41m" << setw(50) << right << " FAMILY MEMBERS \033[0m\n";
        for (const auto& member : household.Family_Members_And_Ages) {
            os << setw(25) << left << "Name: " << setw(25) << right << member.first;
            os << setw(25) << left << "Age: " << setw(25) << right << member.second << "\n";
        }

        os << "\n\033[1;37;41m" << setw(50) << right << " ELECTRICITY INFORMATION \033[0m\n";
        os << setw(25) << left << "Total Consumption: " << setw(25) << right << household.getTotalConsumption() << " kWh\n";
        os << setw(25) << left << "Total Production: " << setw(25) << right << household.getTotalProduction() << " kWh\n";
        os << setw(25) << left << "Current Bill: " << setw(25) << right << household.billAmount << " Dinar\n";

        switch (household.billingStatus) {
            case BillingStatus::NoCharge:
                os << "No charge for this month.\n";
                break;
            case BillingStatus::Payment:
                os << "Your bill amount is " << household.billAmount << " Dinar. Please make a payment.\n";
                break;
            case BillingStatus::Credit:
                os << "Congratulations! You have a credit of " << household.billAmount << " Dinar.\n";
                break;
        }

        if (household.Is_Prize_Winner) {
            os << "\033[1;32mCongratulations! National Prize Winner.\033[0m\n";
        } else {
            os << "\033[1;31mNot eligible for the national prize this month.\033[0m\n";
        }

        os << "\n";

        return os;
    }

    friend istream& operator>>(istream& is, Household& household) {
        cout << "Enter Household Name: ";
        getline(is, household.Account_Holder_Name);

        cout << "Enter Household ID: ";
        is >> household.ID_Number;
        is.ignore(); // Clear the newline character from the buffer

        cout << "Enter Address: ";
        getline(is, household.Address_Info.Address);

        cout << "Enter District: ";
        getline(is, household.Address_Info.District);

        cout << "Enter City: ";
        getline(is, household.Address_Info.City);

        cout << "Enter Region: ";
        getline(is, household.Address_Info.Region);

        cout << "Enter the number of family members: ";
        int numMembers;
        is >> numMembers;
        is.ignore(); // Clear the newline character from the buffer

        household.Family_Members_And_Ages.clear(); // Clear existing family members
        for (int i = 0; i < numMembers; ++i) {
            string name;
            int age;

            cout << "Enter Family Member " << i + 1 << " Name: ";
            getline(is, name);

            cout << "Enter Family Member " << i + 1 << " Age: ";
            is >> age;
            is.ignore(); // Clear the newline character from the buffer

            household.Family_Members_And_Ages.push_back(make_pair(name, age));
        }


        // Allow the user to enter electricity data
        cout << "Enter electricity data (YYYY-MM-DD Consumption Production), enter 'stop' to finish:\n";
        string date;
        while (true) {
            cout << "Enter date (or 'stop' to finish): ";
            getline(is, date);
            if (date == "stop") {
                break;
            }

            size_t consumption, production;
            cout << "Enter consumption: ";
            is >> consumption;
            cout << "Enter production: ";
            is >> production;

            household.addElectricityData(date, consumption, production);

            // Clear the newline character from the buffer
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return is;
    }

     bool operator<(const Household& other) const {
        return ID_Number < other.ID_Number;
    }
    bool operator>(const Household& other) const {
        return ID_Number > other.ID_Number;
    }

    BillingStatus getBillingStatus() const {
        return billingStatus;
    }

    double getBillAmount() const {
        return billAmount;
    }

    void SetBillAmount(double Amount) {
        billAmount = Amount;
    }

    void SetBillStatus(const BillingStatus& value) {
        billingStatus = value;
    }

        
};

