cmake_minimum_required(VERSION 3.28)
project(AreaCalculator LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(AreaCalculator src/main.cpp
        src/formulas.h
        src/ACPoint.cpp
        src/ACPoint.h
)
target_compile_features(AreaCalculator PRIVATE cxx_std_17)
target_link_libraries(AreaCalculator PRIVATE SFML::Graphics)
