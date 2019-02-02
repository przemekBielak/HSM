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

TEST_CASE("state addTransition getTransition") {
    State stIdle        (NULL,           &onIdle);
    State stShutDown    (&stIdle,        &onShutdown);
    State stStartUp     (&stIdle,        &onStartup);

    int err1 = stIdle.addTransition({EV_NO_EVENT, &stIdle});
    REQUIRE(EV_NO_EVENT == stIdle.getTransition().back().event);
    REQUIRE(&stIdle == stIdle.getTransition().back().nextState);
    REQUIRE(err1 == 0);

    int err2 = stStartUp.addTransition({EV_SHUTDOWN, &stShutDown});
    REQUIRE(EV_SHUTDOWN == stStartUp.getTransition().back().event);
    REQUIRE(&stShutDown == stStartUp.getTransition().back().nextState);
    REQUIRE(err2 == 0);

    int err3 = stShutDown.addTransition({EV_STARTUP,         &stStartUp});
    REQUIRE(EV_STARTUP == stShutDown.getTransition().back().event);
    REQUIRE(&stStartUp == stShutDown.getTransition().back().nextState);
    REQUIRE(err3 == 0);

    /* Event already exists, do not add new elements and return error */
    err3 = stShutDown.addTransition({EV_STARTUP, &stShutDown});
    REQUIRE(EV_STARTUP == stShutDown.getTransition().back().event);
    REQUIRE(&stStartUp == stShutDown.getTransition().back().nextState);
    REQUIRE(err3 == -1);
}