cmake_minimum_required(VERSION 3.26)
project(DSA_ECMS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)

add_executable(DSA_ECMS
        Headers/Billing.h
        Headers/BST.h
        Headers/city.h
        Headers/country.h
        Headers/Date.h
        Headers/department.h
        Headers/District.h
        Headers/ElectricityData.h
        Headers/HouseHold.h
        Headers/region.h
        Headers/Weather.h
        Source/Billing.cpp
        Source/city.cpp
        Source/country.cpp
        Source/Date.cpp
        Source/department.cpp
        Source/District.cpp
        Source/ElectricityData.cpp
        Source/HouseHold.cpp
        Source/region.cpp
        Source/Weather.cpp)
