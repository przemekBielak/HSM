#include "catch.hpp"
#include "state.hpp"
#include <iostream>


void onIdle(void) {}
void onShutdown(void) {}
void onStartup(void) {}


TEST_CASE("state getParent") {
    State stIdle        (NULL,           &onIdle);
    State stShutDown    (&stIdle,        &onShutdown);
    State stStartUp     (&stIdle,        &onStartup);

    REQUIRE(stIdle.getParent() == NULL);
    REQUIRE(stShutDown.getParent() == &stIdle);
    REQUIRE(stStartUp.getParent() == &stIdle);
}

TEST_CASE("state getHandler") {
    State stIdle        (NULL,           &onIdle);
    State stShutDown    (&stIdle,        &onShutdown);
    State stStartUp     (&stIdle,        &onStartup);

    REQUIRE(stIdle.getHandler() == &onIdle);
    REQUIRE(stShutDown.getHandler() == &onShutdown);
    REQUIRE(stStartUp.getHandler() == &onStartup);
}