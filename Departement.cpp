#include "Departement.h"

int Department::city_hash(const std::string &city_name) {
    int hashValue = 0;

    for (char ch: city_name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

// Constructor
Department::Department(const std::string& name)
        : cityName(name), departmentID(city_hash(name)), budget(0.0f), amountSpent(0.0f), performance(0.0f), ranking(0) {
    // Your constructor implementation goes here
}

// Destructor
Department::~Department() = default;

// Move Constructor
Department::Department(Department&& other) noexcept
        : cityName(std::move(other.cityName)), departmentID(other.departmentID),
          budget(other.budget), amountSpent(other.amountSpent),
          performance(other.performance), ranking(other.ranking) {}

// Copy Assignment Operator
Department& Department::operator=(const Department& other) {
    if (this != &other) {
        // Your copy assignment implementation goes here
    }
    return *this;
}

// Move Assignment Operator
Department& Department::operator=(Department&& other) noexcept {
    if (this != &other) {
        // Your move assignment implementation goes here
    }
    return *this;
}

// Getter implementations go here

// Setter implementations go here

// Budget functions go here

// Other member function implementations go here
