/**
 * @file main.cpp
 * @author Przemyslaw Bielak (przemyslaw.bielak@protonmail.com)
 * @brief Example usage of HSM.
 * @version 0.1
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include <queue>
#include "stateMachine.hpp"
#include "state.hpp"

void onShutdown(void) {
    std::cout << "Shut down state" << std::endl;
}
void onStartup(void) {
    std::cout << "Start state" << std::endl;
}
void onPlaying(void) {
    std::cout << "Playing state" << std::endl;
}
void onNotPlaying(void) {
    std::cout << "Not playing state" << std::endl;
}

int main(void) {
    
    /* State             Parent       Handler */
    State stShutDown    (nullptr,     &onShutdown);
    State stStart       (nullptr,     &onStartup);
    State stNotPlaying  (&stStart,    &onNotPlaying);
    State stPlaying     (&stStart,    &onPlaying);

    /* State                      Event             Next State */
    stPlaying.addTransition     ({EV_STOP_PLAYING,  &stNotPlaying});
    stNotPlaying.addTransition  ({EV_START_PLAYING, &stPlaying});
    stStart.addTransition       ({EV_SHUTDOWN,      &stShutDown});
    stShutDown.addTransition    ({EV_STARTUP,       &stPlaying});

    std::queue<event_t> eventQueue;
    eventQueue.push(EV_STOP_PLAYING);
    eventQueue.push(EV_START_PLAYING);
    eventQueue.push(EV_SHUTDOWN);

    StateMachine sm(&stPlaying);

    while(true) {
        if(!eventQueue.empty()) {
            event_t nextEvent = eventQueue.front();
            eventQueue.pop();

            /* sm.run doesn't rely on a fixed interfaces. Next event can be provided by any function/queue, etc. 
             * In this case, std::queue was used. */
            sm.run(nextEvent);
        }
    }

    return 0;
}