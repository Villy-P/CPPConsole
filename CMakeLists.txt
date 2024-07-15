cmake_minimum_required(VERSION 3.10)
project(CPP_CONSOLE VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

add_executable(CPP_CONSOLE 
    "${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp"
)

set_target_properties(CPP_CONSOLE PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_options(CPP_CONSOLE PRIVATE 
    "-Wall" 
    "-std=c++17"
    "-fdiagnostics-color=always"
    "-g"
)