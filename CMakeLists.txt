cmake_minimum_required()

project(project-euler)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

add_executable(${PROJECT_NAME} 21-30/29.cpp)

find_package(Boost 1.81 REQUIRED COMPONENTS timer)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::timer)