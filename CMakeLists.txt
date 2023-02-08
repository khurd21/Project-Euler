cmake_minimum_required()

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)
set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)

project(project-euler)

add_executable(${PROJECT_NAME} 21-30/30.cpp)

find_package(Boost 1.81 REQUIRED COMPONENTS timer)
find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::timer)