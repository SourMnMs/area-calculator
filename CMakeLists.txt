cmake_minimum_required(VERSION 3.28)
project(AreaCalculator LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# This is for the "SFML-3.0.0" directory
# Without these two lines "SFML-3.0.0" is useless
#set(SFML_DIR "SFML-3.0.0/lib/cmake/SFML")
#find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(AreaCalculator src/main.cpp
        include/formulas.h
        src/ACPoint.cpp
        include/ACPoint.h
        include/ACLine.h
        src/ACLine.cpp
        src/ACShapeHandler.cpp
        include/ACShapeHandler.h
        include/ACTriangle.h
        src/ACTriangle.cpp
)
target_compile_features(AreaCalculator PRIVATE cxx_std_17)
target_link_libraries(AreaCalculator PRIVATE SFML::Graphics SFML::Window SFML::System)
#include_directories(${SFML_INCLUDE_DIR})
#target_link_libraries(AreaCalculator ${SFML_LIBRARIES})