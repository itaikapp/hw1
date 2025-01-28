cmake_minimum_required(VERSION 3.2)
project(home_work_1 CXX)

set(TARGET "run")

# Set C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add debugging information
set(CMAKE_BUILD_TYPE RelWithDebInfo)

# Include the library
include_directories(
  include
)

file(GLOB SOURCES "src/*.cpp")

add_executable(${TARGET} ${SOURCES})
