#include"../Headers/ElectricityData.h"


void Electricity_Data::add_data(const Date &date, double consumption, double production) {
    // Check if the date already exists
    if (search_date(date)) {
        // Handle the case where data for the specified date already exists
        throw std::invalid_argument("Data for the specified date already exists.");
    }

    // Insert consumption and production data for a specific date
    consumption_production_data[date] = std::make_pair(consumption, production);
}

// Get consumption and production data for a specific date
std::pair<double, double> Electricity_Data::get_data(const Date &date) const {
    auto it = consumption_production_data.find(date);
    if (it != consumption_production_data.end()) {
        return it->second;
    } else {
        // Handle the case where data for the specified date is not found
        throw std::out_of_range("Data not found for the specified date.");
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
double Electricity_Data::get_average_consumption_production() const {
    double sum = 0;
    for (const auto &data: consumption_production_data) {
        sum += data.second.first + data.second.second;
    }

    return (consumption_production_data.size() > 0) ? sum / (2 * consumption_production_data.size()) : 0.0;
}

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
    double totalProduction = 0.0;

    for (const auto &data: consumption_production_data) {
        if (data.first.getYear() == year && data.first.getMonth() == month) {
            totalProduction += data.second.second;  // Accumulate production for the specified month
        }
    }

    return totalProduction;
}

double Electricity_Data::monthlyConsumption(int year, int month) const {
    double totalConsumption = 0.0;

    for (const auto &data: consumption_production_data) {
        if (data.first.getYear() == year && data.first.getMonth() == month) {
            totalConsumption += data.second.first;  // Accumulate consumption for the specified month
        }
    }

    return totalConsumption;
}

double Electricity_Data::yearlyProduction(int year) const {
    double totalProduction = 0.0;

    for (const auto &data: consumption_production_data) {
        if (data.first.getYear() == year) {
            totalProduction += data.second.second;  // Accumulate production for the specified year
        }
    }

    return totalProduction;
}

double Electricity_Data::yearlyConsumption(int year) const {
    double totalConsumption = 0.0;

    for (const auto &data: consumption_production_data) {
        if (data.first.getYear() == year) {
            totalConsumption += data.second.first;  // Accumulate consumption for the specified year
        }
    }

    return totalConsumption;
}


void Electricity_Data::delete_data(const Date &date) {
    auto it = consumption_production_data.find(date);
    if (it != consumption_production_data.end()) {
        consumption_production_data.erase(it);
    } else {
        // Handle the case where data for the specified date is not found
        throw std::out_of_range("Data not found for the specified date.");
    }
}

void Electricity_Data::update_data(const Date &date, double new_consumption, double new_production) {
    auto it = consumption_production_data.find(date);
    if (it != consumption_production_data.end()) {
        // Update consumption and production for the specified date
        it->second = std::make_pair(new_consumption, new_production);
    } else {
        // Handle the case where data for the specified date is not found
        throw std::out_of_range("Data not found for the specified date.");
    }
}


bool Electricity_Data::search_date(const Date &date) const {
    return consumption_production_data.find(date) != consumption_production_data.end();
}

std::vector<std::pair<Date, std::pair<double, double>>>
Electricity_Data::get_data_in_range(const Date &start_date, const Date &end_date) const {
    std::vector<std::pair<Date, std::pair<double, double>>> data_in_range;

    for (const auto &data: consumption_production_data) {
        const Date &current_date = data.first;

        // Check if the current date is within the specified range
        if (current_date >= start_date && current_date <= end_date) {
            data_in_range.push_back(data);
        }
    }

    return data_in_range;
}

std::vector<std::pair<Date, double>> Electricity_Data::get_consumption_in_month(int year, int month) const {
    std::vector<std::pair<Date, double>> consumption_in_month;

    for (const auto &data: consumption_production_data) {
        const Date &current_date = data.first;

        // Check if the current date is within the specified month and year
        if (current_date.getYear() == year && current_date.getMonth() == month) {
            consumption_in_month.emplace_back(current_date, data.second.first);
        }
    }

    return consumption_in_month;
}

std::vector<std::pair<Date, double>> Electricity_Data::get_production_in_month(int year, int month) const {
    std::vector<std::pair<Date, double>> production_in_month;

    for (const auto &data: consumption_production_data) {
        const Date &current_date = data.first;

        // Check if the current date is within the specified month and year
        if (current_date.getYear() == year && current_date.getMonth() == month) {
            production_in_month.emplace_back(current_date, data.second.second);
        }
    }

    return production_in_month;
}

std::vector<std::pair<Date, double>> Electricity_Data::get_consumption_in_year(int year) const {
    std::vector<std::pair<Date, double>> consumption_in_year;

    for (const auto &data: consumption_production_data) {
        const Date &current_date = data.first;

        // Check if the current date is within the specified year
        if (current_date.getYear() == year) {
            consumption_in_year.emplace_back(current_date, data.second.first);
        }
    }

    return consumption_in_year;
}

std::vector<std::pair<Date, double>> Electricity_Data::get_production_in_year(int year) const {
    std::vector<std::pair<Date, double>> production_in_year;

    for (const auto &data: consumption_production_data) {
        const Date &current_date = data.first;

        // Check if the current date is within the specified year
        if (current_date.getYear() == year) {
            production_in_year.emplace_back(current_date, data.second.second);
        }
    }

    return production_in_year;
}


