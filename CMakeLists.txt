project(advent LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(advent
        "7b.cpp"
)