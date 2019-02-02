#include "catch.hpp"
#include "stateMachine.hpp"


TEST_CASE("stateMachine sumTest") {
    REQUIRE(sumTest(1, 3) == 4);
    REQUIRE(sumTest(5, -4) == 1);
}


