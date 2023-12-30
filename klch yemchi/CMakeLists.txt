cmake_minimum_required(VERSION 3.26)
project(klch_yemchi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(klch_yemchi
        Billing.cpp
        Billing.h
        BST.h
        city.cpp
        city.h
        country.cpp
        country.h
        Date.cpp
        Date.h
        department.cpp
        department.h
        District.cpp
        District.h
        ElectricityData.cpp
        ElectricityData.h
        HouseHold.cpp
        HouseHold.h
        json.hpp
        region.cpp
        region.h
        test.cpp
        Weather.cpp
        Weather.h)
