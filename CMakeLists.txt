cmake_minimum_required(VERSION 3.10)
project(CPP_CONSOLE VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME "CPP_CONSOLE")
if (UNIX)
    set(PROJECT_NAME "CPP_CONSOLE.exe")
endif()

include_directories(include/)

add_executable(${PROJECT_NAME} 
    "${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp"
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_options(${PROJECT_NAME} PRIVATE 
    "-Wall" 
    "-std=c++17"
    "-fdiagnostics-color=always"
    "-g"
)