#include <spdlog/spdlog.h>
#include <vector>
#include <numeric>
#include <ranges>
// #include <iostream>

int main() {
    spdlog::info("Distributed Cache Server Starting on macOS Tahoe...");

    // Testing C++20 Ranges and Spdlog
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto even_view = v | std::views::filter([](int n){ return n % 2 == 0; });
    
    spdlog::info("Environment check: C++20 Ranges functional.");
    for (int n : even_view) {
        spdlog::info("Even number: {}", n);
    }

    return 0;
}

/*

commands to run : 

conan install . --build=missing -s compiler.cppstd=20

cmake -S . -B build \\n    -DCMAKE_TOOLCHAIN_FILE=build/build/Debug/generators/conan_toolchain.cmake \\n    -DCMAKE_BUILD_TYPE=Debug

cmake --build build

./build/cache_server

*/