cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)
set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)

project(project-euler)

add_executable(${PROJECT_NAME} 41-50/43.cpp)

find_package(Boost 1.82 REQUIRED COMPONENTS timer)
find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::timer)
