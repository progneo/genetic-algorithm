cmake_minimum_required(VERSION 2.8.12)
project(genetic_algorithm)

include(FetchContent)
FetchContent_Declare(matplotplusplus
        GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
        GIT_TAG origin/master)

FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

set(SOURCE_EXE src/main.cpp)

set(SOURCE_LIB
    src/tools/tools.cpp
    src/ga/crossover.cpp
    src/ga/fitness.cpp
    src/ga/individual.cpp
    src/ga/mutation.cpp
    src/ga/population.cpp
    src/ga/selection.cpp)

add_library(tools SHARED ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})
target_link_libraries(main PUBLIC matplot tools)