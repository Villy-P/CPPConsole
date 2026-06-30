cmake_minimum_required(VERSION 3.10)
project(CPP_CONSOLE VERSION 1.0.0)

set(EXEC_NAME_TEST "CPP_CONSOLE")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Interface library: anything that links cppconsole::cppconsole gets the
# include path automatically.
add_library(cppconsole INTERFACE)
add_library(cppconsole::cppconsole ALIAS cppconsole)
target_include_directories(cppconsole INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# TODO: Move away from using GLOB_RECURSE and explicitly list source files for better maintainability
file(GLOB_RECURSE CPPCONSOLE_TEST_SOURCES CONFIGURE_DEPENDS "test/*.cpp")

add_executable(${EXEC_NAME_TEST} ${CPPCONSOLE_TEST_SOURCES})

target_compile_options(${EXEC_NAME_TEST} PRIVATE
    "-Wall"
    "-Wextra"
    "-fdiagnostics-color=always"
    "$<$<CONFIG:Debug>:-g>"
)

target_link_libraries(${EXEC_NAME_TEST} PRIVATE cppconsole::cppconsole)