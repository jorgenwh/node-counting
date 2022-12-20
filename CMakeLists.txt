cmake_minimum_required(VERSION 3.16)
project(nc_backend LANGUAGES CXX)

find_package(pybind11 REQUIRED)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_CXX_FLAGS "-O3 -march=native -mavx")

set(SOURCE_DIR "nc/backend")
include_directories(${SOURCE_DIR})

set(SOURCES 
  "${SOURCE_DIR}/mapper.cpp"
)

pybind11_add_module(${PROJECT_NAME} ${SOURCES} "${SOURCE_DIR}/bindings.cpp")
