CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

project(
    prime
    VERSION 0.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Werror -Wall -Wextra -pedantic-errors -fmax-errors=1 -Wno-error=ignored-qualifiers")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

include(cmake/CPM.cmake)
CPMAddPackage("gh:catchorg/Catch2@3.3.2")

set(PROJECT_LIBRARY ${PROJECT_NAME})
set(HEADER_DIR ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/source)

include_directories(${HEADER_DIR})

set(
    PROJECT_SOURCE_FILES
    ${SOURCE_DIR}/Prime.cpp
)

add_library(${PROJECT_LIBRARY} SHARED ${PROJECT_SOURCE_FILES})
target_link_libraries(${PROJECT_LIBRARY} m Catch2::Catch2WithMain)

enable_testing()
add_subdirectory(test)
add_subdirectory(benchmark)

message("\n")
message("---- Project ${PROJECT_NAME} ----")
message("Version               = ${PROJECT_VERSION}")
message("Homepage              = ${PROJECT_HOMEPAGE_URL}")
message("C++ compiler          = ${CMAKE_CXX_COMPILER}")
message("Compiler version      = ${CMAKE_CXX_COMPILER_VERSION}")
message("Compiler flags        = ${CMAKE_CXX_FLAGS}")
message("\n")
