#include"ElectricityData.h"


void Electricity_Data::add_data(const Date &date, double consumption, double production) {
    // Check if the date already exists
    if (search_date(date)) {
        // Handle the case where data for the specified date already exists
        throw invalid_argument("Data for the specified date already exists.");
    }

    // Insert consumption and production data for a specific date
    consumption_production_data[date] = make_pair(consumption, production);
}

// Get the Map of Consumption and Production ** Needed for the in HouseHoldToJson **
map<Date, pair<double, double>> Electricity_Data::get_consumption_production_data() const{
    return consumption_production_data;
}

// Get consumption and production data for a specific date
pair<double, double> Electricity_Data::get_data(const Date &date) const {
    auto it = consumption_production_data.find(date);
    if (it != consumption_production_data.end()) {
        return it->second;
    } else {
        // Handle the case where data for the specified date is not found
        return make_pair(0, 0);
    }
}

// Get consumption for a specific date
double Electricity_Data::get_consumption(const Date &date) const {
    return get_data(date).first;
}

// Get production for a specific date
double Electricity_Data::get_production(const Date &date) const {
    return get_data(date).second;
}

// Calculate the average consumption over all dates
double Electricity_Data::get_average_consumption() const {
    double sum = 0;
    for (const auto &data: consumption_production_data) {
        sum += data.second.first;
    }

    return (consumption_production_data.size() > 0) ? sum / consumption_production_data.size() : 0.0;
}

// Calculate the average production over all dates
double Electricity_Data::get_average_production() const {
    double sum = 0;
    for (const auto &data: consumption_production_data) {
        sum += data.second.second;
    }

    return (consumption_production_data.size() > 0) ? sum / consumption_production_data.size() : 0.0;
}

// Calculate the average of the sum of consumption and production over all dates
// double Electricity_Data::get_average_consumption_production() const {
//     double sum = 0;
//     for (const auto& data : consumption_production_data) {
//         sum += data.second.first + data.second.second;
//     }

//     return (consumption_production_data.size() > 0) ? sum / (2 * consumption_production_data.size()) : 0.0;
// }

// Get the total consumption for all dates
double Electricity_Data::get_total_consumption() const {
    double total_consumption = 0;
    for (const auto &data: consumption_production_data) {
        total_consumption += data.second.first;
    }
    return total_consumption;
}

// Get the total production for all dates
double Electricity_Data::get_total_production() const {
    double total_production = 0;
    for (const auto &data: consumption_production_data) {
        total_production += data.second.second;
    }
    return total_production;
}

// Get the difference between total production and total consumption
double Electricity_Data::get_production_consumption_difference() const {
    return get_total_consumption() - get_total_production();
}


double Electricity_Data::monthlyProduction(int year, int month) const {
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return getProductionInRange(year, month, 1, year, month, daysInMonth[month]);
}

double Electricity_Data::monthlyConsumption(int year, int month) const {
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return getConsumptionInRange(year, month, 1, year, month, daysInMonth[month]);
}

double Electricity_Data::yearlyProduction(int year) const {
    return getProductionInRange(year, 1, 1, year, 12, 31);
}

double Electricity_Data::yearlyConsumption(int year) const {
    return getConsumptionInRange(year, 1, 1, year, 12, 31);
}


void Electricity_Data::delete_data(const Date &date) {
    auto it = consumption_production_data.find(date);
    if (it != consumption_production_data.end()) {
        consumption_production_data.erase(it);
    } else {
        // Handle the case where data for the specified date is not found
        throw out_of_range("Data not found for the specified date.");
    }
}

void Electricity_Data::update_data(const Date &date, double new_consumption, double new_production) {
    auto it = consumption_production_data.find(date);
    if (it != consumption_production_data.end()) {
        // Update consumption and production for the specified date
        it->second = make_pair(new_consumption, new_production);
    } else {
        // Handle the case where data for the specified date is not found
        throw out_of_range("Data not found for the specified date.");
    }
}


bool Electricity_Data::search_date(const Date &date) const {
    return consumption_production_data.find(date) != consumption_production_data.end();
}

vector<pair<Date, pair<double, double>>>
Electricity_Data::get_data_in_range(int year1, int month1, int day1, int year2, int month2, int day2) const {
    vector<pair<Date, pair<double, double>>> data_in_range;
    Date date1(day1, month1, year1), date2(day2, month2, year2);
    for (Date i = date1; i <= date2; ++i) {
        data_in_range.push_back(make_pair(i, get_data(i)));
    }
    return data_in_range;
}

vector<pair<Date, pair<double, double>>> Electricity_Data::getMonthlyData(int month, int year) const {
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return get_data_in_range(year, month, 1, year, month, daysInMonth[month]);
}

vector<pair<Date, pair<double, double>>> Electricity_Data::getYearlyData(int year) const {
    return get_data_in_range(year, 1, 1, year, 12, 31);
}


double Electricity_Data::getProductionInRange(int year1, int month1, int day1, int year2, int month2, int day2) const {
    Date date1(day1, month1, year1), date2(day2, month2, year2);
    double totalProduction = 0;
    for (Date i = date1; i <= date2; ++i) {
        totalProduction += get_production(i);
    }
    return totalProduction;
}

double Electricity_Data::getConsumptionInRange(int year1, int month1, int day1, int year2, int month2, int day2) const {
    Date date1(day1, month1, year1), date2(day2, month2, year2);
    double totalConsumption = 0;
    for (Date i = date1; i <= date2; ++i) {
        totalConsumption += get_consumption(i);
    }
    return totalConsumption;
}


nlohmann::json Electricity_Data::ElectrecityDataToJson() const {
    nlohmann::json json;
    for (const auto &entry: consumption_production_data) {
        json.push_back({
                               {"Date",        entry.first.DateToJson()},
                               {"Consumption", entry.second.first},
                               {"Production",  entry.second.second}
                       });
    }
    return json;
}

Electricity_Data Electricity_Data::ElecFromJson(const nlohmann::json &jsonFile) {
    if (!jsonFile.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }

    Electricity_Data elecData;
    for (const auto& entry : jsonFile) {
        Date date = Date::DateFromJson(entry["Date"]);
        double consumption = entry["Consumption"].get<double>();
        double production = entry["Production"].get<double>();
        elecData.add_data(date, consumption, production);
    }
    return elecData;
}

