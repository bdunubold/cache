#include <catch2/catch_test_macros.hpp>

TEST_CASE("Sanity Check", "[setup]") {
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Standard Library Check", "[setup]") {
    std::vector<int> v = {10, 20};
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 10);
}