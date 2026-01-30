cmake_minimum_required(VERSION 3.20)
project(DistributedCache VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Dependencies ---
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(Catch2 3 REQUIRED)

# --- 2. Compiler Flags (Success Metric: Zero Warnings) ---
add_library(project_warnings INTERFACE)
target_compile_options(project_warnings INTERFACE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Wall -Wextra -Wpedantic -Werror -Wshadow -Wconversion>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic -Werror -Wshadow -Wconversion>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

# --- 3. Sanitizer Options (Critical for Debugging) ---
option(ENABLE_SANITIZER_ADDRESS "Enable Address Sanitizer" ON)
if(ENABLE_SANITIZER_ADDRESS)
    add_compile_options(-fsanitize=address -g)
    add_link_options(-fsanitize=address)
endif()

# --- 4. Main Executable ---
add_executable(cache_server src/main.cpp)
target_link_libraries(cache_server PRIVATE 
    project_warnings 
    spdlog::spdlog 
    fmt::fmt
)

# --- 5. Tests ---
enable_testing()
add_executable(unit_tests tests/test_main.cpp)
target_link_libraries(unit_tests PRIVATE 
    project_warnings 
    Catch2::Catch2WithMain
)