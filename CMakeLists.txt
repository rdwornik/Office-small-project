cmake_minimum_required(VERSION 3.7)
project(PROJEKT_EOOP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        customer.cpp
        customer.h
        Employee.cpp
        Employee.h
        ListCustomer.cpp
        ListCustomer.h
        ListEmployee.cpp
        ListEmployee.h
        main.cpp
        office.cpp
        Office.h)

add_executable(PROJEKT_EOOP ${SOURCE_FILES})