#include "catch.hpp"
#include "stateMachine.hpp"

void func1(void) {}
void func2(void) {}
void func3(void) {}
void func4(void) {}

TEST_CASE("stateMachine getCurrState") {
    State stStartUp(NULL, &func3);

    StateMachine sm(&stStartUp);
    REQUIRE(sm.getCurrState() == &stStartUp);

    StateMachine sm2(NULL);
    REQUIRE(sm2.getCurrState() == NULL);
}

TEST_CASE("stateMachine run") {
    State stPlaying     (NULL,           &func4);
    State stNotPlaying  (NULL,           &func3);
    State stIdle        (&stPlaying,     &func1);
    State stShutDown    (&stIdle,        &func2);
    State stStartUp     (&stIdle,        &func3);

    stStartUp.addTransition({EV_SHUTDOWN, &stShutDown});
    stIdle.addTransition({EV_NO_EVENT, &stStartUp});
    stPlaying.addTransition({EV_STOP_PLAYING, &stNotPlaying});
    stNotPlaying.addTransition({EV_START_PLAYING, &stPlaying});

    StateMachine sm(&stStartUp);

    /* Check event directly connected with state */
    /* currState --> stStartUp */
    bool found1 = sm.run(EV_SHUTDOWN); 
    REQUIRE(sm.getCurrState() == &stShutDown);
    REQUIRE(found1 == true);

    /* Check event from parent */
    /* currState --> stShutDown */
    bool found2 = sm.run(EV_NO_EVENT);
    REQUIRE(sm.getCurrState() == &stStartUp);
    REQUIRE(found2 == true);

    /* Check event from parent's parent */
    /* currState --> stStartUp */
    bool found3 = sm.run(EV_STOP_PLAYING);
    REQUIRE(sm.getCurrState() == &stNotPlaying);
    REQUIRE(found3 == true);

    /* Check not possible event */
    /* currState --> stNotPlaying */
    bool found4 = sm.run(EV_STOP_PLAYING);
    REQUIRE(sm.getCurrState() == &stNotPlaying);
    REQUIRE(found4 == false);
}

