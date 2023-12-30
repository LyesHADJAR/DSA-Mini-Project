#include"Date.h"

bool Date::isLeapYear(int NewYear) {
    return (NewYear % 4 == 0 && NewYear % 100 != 0) || (NewYear % 400 == 0);
}

Date::Date(int NewDay, int NewMonth, int NewYear, const Weather &CurrentWeather) {
    setYear(NewYear);
    setMonth(NewMonth);
    setDay(NewDay);
    setWeather(CurrentWeather);
}

Date::Date() {
    time_t currentTime = time(nullptr);
    tm currentDate = *localtime(&currentTime);
    Day = currentDate.tm_mday;
    Month = currentDate.tm_mon + 1;
    Year = currentDate.tm_year + 1900;
}

void Date::CurrentDay() {
    time_t currentTime = time(nullptr);
    tm currentDate = *localtime(&currentTime);
    setDay(currentDate.tm_mday);
    setMonth(currentDate.tm_mon + 1);
    setYear(currentDate.tm_year + 1900);
}

void Date::setCurrentDate() {
    this->CurrentDay();
}

void Date::setYear(int NewYear) {

    if (NewYear < 0) {
        throw invalid_argument("Invalid year: Year cannot be negative.");
    } else {
        Year = NewYear;
    }
}

int Date::getYear() const {
    return Year;
}

void Date::setWeather(const Weather &newWeather) {
    Day_Weather = newWeather;
}

void Date::setMonth(int NewMonth) {

    if (NewMonth < 1 || NewMonth > 12) {
        throw invalid_argument("Invalid month: Month must be between 1 and 12.");
    } else {
        Month = NewMonth;
    }
}

int Date::getMonth() const {
    return Month;
}

void Date::setDay(int NewDay) {
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Adjust February for leap years
    if (getMonth() == 2) {
        if (isLeapYear(getYear())) {
            daysInMonth[2] = 29;
        } else {
            daysInMonth[2] = 28; // Reset to 28 if it's not a leap year
        }
    }

    if (NewDay < 1 || NewDay > daysInMonth[getMonth()]) {
        throw invalid_argument("Invalid day: Day must be between 1 and the number of days in the month.");
    } else {
        Day = NewDay;
    }
}

int Date::getDay() const {
    return Day;
}

Weather Date::getWeatherInfo() const {
    return Day_Weather;
}

namespace std {
    template<>
    struct hash<Date> {
        std::size_t operator()(const Date &date) const {
            return hash<int>()(date.getDay()) ^
                   hash<int>()(date.getMonth()) ^
                   hash<int>()(date.getYear());
        }
    };

    template<>
    struct equal_to<Date> {
        bool operator()(const Date &lhs, const Date &rhs) const {
            return lhs == rhs;
        }
    };
}

bool Date::operator>=(const Date &other) const {
    // Assuming a comparison based on year, month, and day
    if (Year > other.Year) {
        return true;
    } else if (Year == other.Year) {
        if (Month > other.Month) {
            return true;
        } else if (Month == other.Month) {
            return Day >= other.Day;
        }
    }

    return false;
}

bool Date::operator<=(const Date &other) const {
    // Assuming a comparison based on year, month, and day
    if (Year < other.Year) {
        return true;
    } else if (Year == other.Year) {
        if (Month < other.Month) {
            return true;
        } else if (Month == other.Month) {
            return Day <= other.Day;
        }
    }

    return false;
}

Date *Date::operator++() {
    if (Month == 12 && Day == 31) {
        Day = 1;
        Month = 1;
        Year++;
    } else {
        int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (getMonth() == 2) {
            if (isLeapYear(getYear())) {
                daysInMonth[2] = 29;
            } else {
                daysInMonth[2] = 28; // Reset to 28 if it's not a leap year
            }
        }
        if (Day == daysInMonth[Month]) {
            Day = 1;
            Month++;
        } else Day++;
    }
    return this;
}

nlohmann::json Date::DateToJson() const {
    nlohmann::json json;
    json["Day"] = Day;
    json["Month"] = Month;
    json["Year"] = Year;
    json["Day_Weather"] = Day_Weather.weatherToJson();
    return json;
}

Date Date::DateFromJson(const nlohmann::json &jsonFile) {
    if (!jsonFile.is_object()) {
        throw std::invalid_argument("Invalid JSON format: Expected an object.");
    }
    Date date(
            jsonFile["Day"].get<int>(),
            jsonFile["Month"].get<int>(),
            jsonFile["Year"].get<int>(),
            Weather::weatherFromJson(jsonFile["Day_Weather"])
    );

    return date;
}
