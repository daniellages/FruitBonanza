# cmake -G "MinGW Makefiles" ..
# cmake --build .

# Define the cmake version
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(FruitBonanza)

# Activate C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(HELPER_DIR ${CMAKE_SOURCE_DIR}/helper)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Add every cpp
file(GLOB SOURCES ${SRC_DIR}/*.cpp ${HELPER_DIR}/*.cpp)

# Include header files from helper
include_directories(${HELPER_DIR} ${INCLUDE_DIR})

# Get executable
add_executable(FruitBonanza ${SOURCES})

# Config output folder for .exe and .of
set_target_properties(FruitBonanza PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    OUTPUT_NAME main
)