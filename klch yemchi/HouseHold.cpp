#include"HouseHold.h"

#include <utility>

HouseHold::HouseHold(vector<int> Ages, string Customer_Name, int membersNumber, string Customer_Address, string ID,
                     District *d) : district(d) {
    setAccountHolderName(std::move(Customer_Name));
    setFamilyMembers(membersNumber);
    setFamilyMembersAges(std::move(Ages));
    setAddress(std::move(Customer_Address));
    districtID = std::move(ID);
    setID();
}

HouseHold::HouseHold(string ID) {
    districtID = std::move(ID);
    setID();
    setAccountHolderName("Unknown");
    setFamilyMembers(0);
    setFamilyMembersAges(vector<int>{});
    // setAddress("unknown");
}

void HouseHold::setID() {
    householdID = districtID;
    int nextID;
    do {
        nextID = rand() % 9999999 + 1;
    } while (district->isIDUsed(nextID));
    int length = to_string(nextID).length();
    for (int i = 0; i < 7 - length; i++) householdID += "0";
    householdID += to_string(nextID);
}

string HouseHold::getAccountHolderName() const {
    if (this == nullptr) return "null";
    return Account_Holder_Name;
}

string HouseHold::getIDNumber() const {
    if (this == nullptr) return "HOUSEHOLD DOESN'T EXIST";
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
    // if (Customer_Name.empty()) {
    //     throw invalid_argument("Invalid Customer Name");
    // }
    //         // Check if all characters in the name are letters or spaces
    // for (char ch : Customer_Name) {
    //     if (!isalpha(ch) && !isspace(ch)) {
    //         throw invalid_argument("Invalid Customer Name (all characters in the name Must be letters or spaces)");
    //     }
    // }

    // // Check if the name does not start or end with a space
    // if (isspace(Customer_Name.front()) ) {
    //     throw invalid_argument("Invalid Customer Name (Customer Name does not start with a space)");
    // }
    Account_Holder_Name = std::move(Customer_Name);
}

void HouseHold::setFamilyMembers(int membersNumber) {
    if (membersNumber < 0) {
        throw invalid_argument("Invalid Number of Members");
    }
    Family_Members = membersNumber;
}

void HouseHold::setFamilyMembersAges(vector<int> Ages) {
    if (getFamilyMembers() != Ages.size()) {
        throw invalid_argument("Invalid Number of Members");
    }
    for (int element: Ages) {
        if (element < 0) {
            throw invalid_argument("Invalid Age");
        }
        Family_Members_Ages = Ages;
    }
}

void HouseHold::setAddress(string Customer_Address) {
    if (Customer_Address.empty()) {
        throw invalid_argument("Invalid Address");
    }
    Address = Customer_Address;
}

void HouseHold::setIsPrizeWinner(bool Value) {
    Is_Prize_Winner = Value;
}


void HouseHold::addElectricityData(const Date &New_Date, double Consumption, double Production) {
    if (Consumption < 0 || Production < 0) {
        throw invalid_argument("Invalid Consumption or Production");
    }
    HouseHold_Electricity_Data.add_data(New_Date, Consumption, Production);
}

// Get consumption and production data for a specific date
pair<double, double> HouseHold::getElectricityData(const Date &date) {
    return HouseHold_Electricity_Data.get_data(date);
}

// Get total consumption for all dates
double HouseHold::getTotalConsumption() const {
    return HouseHold_Electricity_Data.get_total_consumption();
}

// Get total production for all dates
double HouseHold::getTotalProduction() const {
    return HouseHold_Electricity_Data.get_total_production();
}

// Get the difference between total production and total consumption
double HouseHold::getProductionConsumptionDifference() const {
    return HouseHold_Electricity_Data.get_production_consumption_difference();
}

double HouseHold::monthlyConsumption(int year, int month) const {
    return HouseHold_Electricity_Data.monthlyConsumption(year, month);
}

double HouseHold::monthlyProduction(int year, int month) const {
    return HouseHold_Electricity_Data.monthlyProduction(year, month);
}


vector<pair<Date, pair<double, double>>>
HouseHold::get_data_in_range(int year1, int month1, int day1, int year2, int month2, int day2) const {
    return HouseHold_Electricity_Data.get_data_in_range(year1, month1, day1, year2, month2, day2);
}

vector<pair<Date, pair<double, double>>> HouseHold::getMonthlyData(int month, int year) const {
    return HouseHold_Electricity_Data.getMonthlyData(month, year);
}

vector<pair<Date, pair<double, double>>> HouseHold::getYearlyData(int year) const {
    return HouseHold_Electricity_Data.getYearlyData(year);
}

double HouseHold::yearlyProduction(int year) const {
    return HouseHold_Electricity_Data.yearlyProduction(year);
}

double HouseHold::yearlyConsumption(int year) const {
    return HouseHold_Electricity_Data.yearlyConsumption(year);
}

long double HouseHold::householdYearlyBill(int year) const {
    return 5 * yearlyConsumption(year) - 3 * yearlyProduction(year);
}

double HouseHold::getConsumptionInRange(int year1, int month1, int day1, int year2, int month2, int day2) const {
    if (this == NULL) return 0;
    return HouseHold_Electricity_Data.getConsumptionInRange(year1, month1, day1, year2, month2, day2);
}

double HouseHold::getProductionInRange(int year1, int month1, int day1, int year2, int month2, int day2) const {
    if (this == NULL) { return 0; }
    //  cout<<Account_Holder_Name<<"  "<<HouseHold_Electricity_Data.getConsumptionInRange(year1,month1,day1,year2,month2,day2)<<endl;
    return HouseHold_Electricity_Data.getProductionInRange(year1, month1, day1, year2, month2, day2);
}

string HouseHold::getDistrict_ID() {
    return districtID;
}


nlohmann::json HouseHold::HouseHoldToJson() const {
    nlohmann::json json;
    nlohmann::json electricityDataJson;
    for (const auto &entry: HouseHold_Electricity_Data.get_consumption_production_data()) {
        nlohmann::json entryJson;
        entryJson["Date"] = entry.first.DateToJson();
        entryJson["Consumption"] = entry.second.first;
        entryJson["Production"] = entry.second.second;
        electricityDataJson.push_back(entryJson);
    }

    json["HouseHold_Electricity_Data"] = electricityDataJson;
    json["Account_Holder_Name"] = Account_Holder_Name;
    json["householdID"] = householdID;
    json["districtID"] = districtID;
    json["Family_Members"] = Family_Members;
    json["Address"] = Address;
    json["Is_Prize_Winner"] = Is_Prize_Winner;

    return json;
}

void HouseHold::setDistrict(District *d) {
    district = d;
}

HouseHold HouseHold::HouseHoldFromJson(const nlohmann::json &jsonData) {
    if (!jsonData.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }

    HouseHold household(
            jsonData.value("Family_Members_Ages", std::vector<int>()),
            jsonData["Account_Holder_Name"].get<std::string>(),
            jsonData["Family_Members"].get<int>(),
            jsonData["Address"].get<std::string>(),
            jsonData["householdID"].get<std::string>(),
            nullptr
    );
    if (jsonData.find("HouseHold_Electricity_Data") != jsonData.end()) {
        household.HouseHold_Electricity_Data = Electricity_Data::ElecFromJson(jsonData["HouseHold_Electricity_Data"]);
    }
    return household;
}


/*
    HouseHold household(
            jsonData.value("Family_Members_Ages", std::vector<int>()), // Use default value if the key is not present
            jsonData["Account_Holder_Name"].get<std::string>(),
            jsonData["Family_Members"].get<int>(),
            jsonData["Address"].get<std::string>(),
            jsonData["householdID"].get<std::string>(),
            nullptr
    );

    // Check if "HouseHold_Electricity_Data" is present and is an array
    if (jsonData.find("HouseHold_Electricity_Data") != jsonData.end() &&
        jsonData["HouseHold_Electricity_Data"].is_array()) {
        // Populate Electricity_Data
        for (const auto &entry: jsonData["HouseHold_Electricity_Data"]) {
            // Check if the required keys are present and have the expected types
            if (entry.find("Date") != entry.end() && entry["Date"].is_object() &&
                entry["Date"].find("Day_Weather") != entry["Date"].end() &&
                entry["Date"]["Day_Weather"].is_object()) {

                Weather weather(
                        static_cast<Weather_Conditions>(entry["Date"]["Day_Weather"]["CurrentCondition"].get<int>()),
                        entry["Date"]["Day_Weather"]["MaxTemperature"].get<double>(),
                        entry["Date"]["Day_Weather"]["MinTemperature"].get<double>(),
                        entry["Date"]["Day_Weather"]["SunnyHours"].get<double>()
                );
                Date date(
                        entry["Date"]["Day"].get<int>(),
                        entry["Date"]["Month"].get<int>(),
                        entry["Date"]["Year"].get<int>(),
                        weather
                );
                double consumption = entry.value("Consumption", 0.0); // Use default value if the key is not present
                double production = entry.value("Production", 0.0); // Use default value if the key is not present

                household.HouseHold_Electricity_Data.add_data(date, consumption, production);
            }
        }
    }
*/
