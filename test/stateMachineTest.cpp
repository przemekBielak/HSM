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

    StateMachine sm(&stStartUp);

    /* Check event directly connected with state */
    /* currState --> stStartUp */
    sm.run(EV_SHUTDOWN); 
    REQUIRE(sm.getCurrState() == &stShutDown);

    /* Check event from parent */
    /* currState --> stShutDown */
    sm.run(EV_NO_EVENT);
    REQUIRE(sm.getCurrState() == &stStartUp);

    /* Check event from parent's parent */
    /* currState --> stStartUp */
    sm.run(EV_STOP_PLAYING);
    REQUIRE(sm.getCurrState() == &stNotPlaying);
}

