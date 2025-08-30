cmake_minimum_required(VERSION 3.15)

# Modern project declaration with explicit language specification
project(CPPConsole 
    VERSION 1.0.0
    DESCRIPTION "A header-only C++ library for enhanced console output with colors, cursor control, and formatting"
    HOMEPAGE_URL "https://github.com/Villy-P/CPPConsole"
    LANGUAGES CXX
)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Create header-only interface library
add_library(CPPConsole INTERFACE)
add_library(CPPConsole::CPPConsole ALIAS CPPConsole)

# Set C++ standard and features using modern target-based approach
target_compile_features(CPPConsole INTERFACE cxx_std_17)

# Add include directories using target-based approach
target_include_directories(CPPConsole 
    INTERFACE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Platform-specific compile definitions
if(WIN32)
    target_compile_definitions(CPPConsole INTERFACE __WIN32)
endif()

# Option to build tests (default: ON for development, can be disabled for packaging)
option(CPPCONSOLE_BUILD_TESTS "Build CPPConsole tests" ON)

if(CPPCONSOLE_BUILD_TESTS)
    # Test executable with proper naming convention
    add_executable(CPPConsole_test 
        "${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp"
    )
    
    # Link the test executable to our library
    target_link_libraries(CPPConsole_test PRIVATE CPPConsole::CPPConsole)
    
    # Modern compiler options using generator expressions
    target_compile_options(CPPConsole_test PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -pedantic>
        $<$<CXX_COMPILER_ID:GNU,Clang>:$<$<CONFIG:Debug>:-g -O0>>
        $<$<CXX_COMPILER_ID:GNU,Clang>:$<$<CONFIG:Release>:-O3 -DNDEBUG>>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<CXX_COMPILER_ID:MSVC>:$<$<CONFIG:Debug>:/Od /Zi>>
        $<$<CXX_COMPILER_ID:MSVC>:$<$<CONFIG:Release>:/O2 /DNDEBUG>>
    )
    
    # Set output directory for test executable
    set_target_properties(CPPConsole_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin"
        OUTPUT_NAME "cppconsole_test"
    )
    
    # Enable colored diagnostics if supported
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(CPPConsole_test PRIVATE -fdiagnostics-color=always)
    endif()
endif()

# Installation rules for header-only library
include(GNUInstallDirs)

install(TARGETS CPPConsole
    EXPORT CPPConsoleTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)

install(EXPORT CPPConsoleTargets
    FILE CPPConsoleTargets.cmake
    NAMESPACE CPPConsole::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CPPConsole
)

# Generate and install config files for find_package support
include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPPConsoleConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/CPPConsoleConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CPPConsole
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/CPPConsoleConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/CPPConsoleConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/CPPConsoleConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CPPConsole
)