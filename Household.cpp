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
    vector<pair<string, int>> Family_Members_And_Ages;
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

    static string generateRandomString(size_t length) {
        const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string randomString;

        for (size_t i = 0; i < length; ++i) {
            randomString += characters[rand() % characters.size()];
        }

        return randomString;
    }

    static size_t generateRandomID() {
        return rand() % (999999 - 100000 + 1) + 100000;
    }

    static int generateRandomNumber(int min, int max) {
        return rand() % (max - min + 1) + min;
    }

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

    static Household generateRandomData() {
        Household randomHousehold;

        randomHousehold.Account_Holder_Name = generateRandomString(10); // Generate a random name
        randomHousehold.ID_Number = generateRandomID();  // Generate a random ID
        randomHousehold.Address_Info = {
            generateRandomString(10),  // Generate a random address
            generateRandomString(8),   // Generate a random district
            generateRandomString(8),   // Generate a random city
            generateRandomString(8)    // Generate a random region
        };

        // Generate random family members
        int numMembers = generateRandomNumber(1, 5);  // Random number of family members (1 to 5)
        for (int i = 0; i < numMembers; ++i) {
            randomHousehold.Family_Members_And_Ages.push_back(make_pair(generateRandomString(8), generateRandomNumber(1, 50)));
        }

        // Generate random electricity data
        int numEntries = generateRandomNumber(1, 10);  // Random number of entries (1 to 10)
        for (int i = 0; i < numEntries; ++i) {
            string date = "2023-01-" + to_string(generateRandomNumber(1, 28));  // Random date in January
            size_t consumption = generateRandomNumber(1, 100);  // Random consumption (1 to 100)
            size_t production = generateRandomNumber(0, 50);  // Random production (0 to 50)

            randomHousehold.addElectricityData(date, consumption, production);
        }

        // Calculate bill and check national prize
        randomHousehold.calculateBill();
        randomHousehold.checkNationalPrize();

        return randomHousehold;
    }
};

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Test the generateRandomData function
    Household randomData = Household::generateRandomData();

    // Display the generated random household information
    cout << randomData;

    return 0;
}
