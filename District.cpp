#include "District.h"

// Private helper function for hashing
int District::district_hash(const std::string& district_name) {
    int hashValue = 0;

    for (char ch : district_name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

// Constructor
District::District(const std::string& name) : districtName(name), districtID(district_hash(name)) {}

// Destructor
District::~District() = default;

// Copy constructor
District::District(const District& other) = default;

// Move constructor
District::District(District&& other) noexcept : districtName(std::move(other.districtName)), districtID(other.districtID) {}

// Copy assignment operator
District& District::operator=(const District& other) {
    if (this != &other) {
        districtName = other.districtName;
        districtID = other.districtID;
    }
    return *this;
}

// Move assignment operator
District& District::operator=(District&& other) noexcept {
    if (this != &other) {
        districtName = std::move(other.districtName);
        districtID = other.districtID;
    }
    return *this;
}

