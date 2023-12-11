#include "Region.h"

// Private helper function for hashing
int Region::region_hash(const std::string& region_name) {
    int hashValue = 0;

    for (char ch : region_name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

// Constructor
Region::Region(const std::string& name) : regionName(name), regionID(region_hash(name)) {}

// Destructor
Region::~Region() = default;

// Copy constructor
Region::Region(const Region& other) = default;

// Move constructor
Region::Region(Region&& other) noexcept : regionName(std::move(other.regionName)), regionID(other.regionID) {}

// Copy assignment operator
Region& Region::operator=(const Region& other) {
    if (this != &other) {
        regionName = other.regionName;
        regionID = other.regionID;
    }
    return *this;
}

// Move assignment operator
Region& Region::operator=(Region&& other) noexcept {
    if (this != &other) {
        regionName = std::move(other.regionName);
        regionID = other.regionID;
    }
    return *this;
}