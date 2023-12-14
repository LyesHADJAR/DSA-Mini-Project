#include"../Headers/HouseHold.h"

HouseHold::HouseHold( string Customer_Name ,int membersNumber ,vector<int>Ages, string Customer_Address, string ID ) {
        setAccountHolderName(Customer_Name);
        setFamilyMembers(membersNumber);
        setFamilyMembersAges(Ages);
        setAddress(Customer_Address);
        districtID = ID;
        setID();
}

HouseHold::HouseHold(string ID) {
    districtID = ID;
    setID();
    setAccountHolderName("Unknown");
    setFamilyMembers(0);
    setFamilyMembersAges(vector<int>{});
    setAddress("unkown");
} 

void HouseHold::setID() {
    householdID= districtID;
    int nextID;
    srand(time(0));
    do {
        nextID = rand()%10000000;
    }while(isIdUsed[nextID]);
    isIdUsed[nextID] = 1;
    for(int i = 1; i <=7; i++){
        if(nextID/pow(10,i) == 0) {
            for(int j= 7-i; j >0; j--) householdID+= "0";
            break;
        }
    }
    householdID += to_string(nextID);
    nextID++;
}

string HouseHold::getAccountHolderName() const {
    return Account_Holder_Name;
}
string HouseHold::getIDNumber() const {
    return householdID;
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
        
        void HouseHold::setFamilyMembers(int membersNumber) {
            if (membersNumber < 0) {
                throw std::invalid_argument("Invalid Number of Members");
                }
                Family_Members = membersNumber;
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


    std::vector<std::pair<Date, std::pair<double, double>>> HouseHold::get_data_in_range(const Date& start_date, const Date& end_date) const{
        return HouseHold_Electricity_Data.get_data_in_range(start_date,end_date);
    }

    // Retrieve consumption data for a specific month
    std::vector<std::pair<Date, double>> HouseHold::get_consumption_in_month(int year, int month) const {
        return HouseHold_Electricity_Data.get_consumption_in_month(year,month);
    }

    // Retrieve production data for a specific month
    std::vector<std::pair<Date, double>> HouseHold::get_production_in_month(int year, int month) const {
        return HouseHold_Electricity_Data.get_production_in_month(year,month);
    }

    // Retrieve consumption data for a specific year
    std::vector<std::pair<Date, double>> HouseHold::get_consumption_in_year(int year) const {
        return HouseHold_Electricity_Data.get_consumption_in_year(year);
    }

    // Retrieve production data for a specific year
    std::vector<std::pair<Date, double>> HouseHold::get_production_in_year(int year) const {
        return HouseHold_Electricity_Data.get_production_in_year(year);
    }

    double HouseHold::yearlyProduction(int year) const {
        return HouseHold_Electricity_Data.yearlyProduction(year);
    }
    double HouseHold::yearlyConsumption(int year) const {
       return  HouseHold_Electricity_Data.yearlyConsumption(year);
    }

long double HouseHold::householdYearlyBill(int year)const {
    return 5*yearlyConsumption(year)-3*yearlyProduction(year);
}