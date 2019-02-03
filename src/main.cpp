#include <iostream>
#include <queue>
#include "stateMachine.hpp"

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
    std::queue<event_t> eventQueue;

    /* State             Parent       Handler */
    State stShutDown    (NULL,        &onShutdown);
    State stStart       (NULL,        &onStartup);
    State stNotPlaying  (&stStart,    &onNotPlaying);
    State stPlaying     (&stStart,    &onPlaying);

    /* State                      Event             Next State */
    stPlaying.addTransition     ({EV_STOP_PLAYING,  &stNotPlaying});
    stNotPlaying.addTransition  ({EV_START_PLAYING, &stPlaying});
    stStart.addTransition       ({EV_SHUTDOWN,      &stShutDown});
    stShutDown.addTransition    ({EV_STARTUP,       &stPlaying});

    StateMachine sm(&stPlaying);

    eventQueue.push(EV_STOP_PLAYING);
    eventQueue.push(EV_START_PLAYING);
    eventQueue.push(EV_SHUTDOWN);

    while(true) {
        if(!eventQueue.empty()) {
            event_t nextEvent = eventQueue.front();
            eventQueue.pop();
            sm.run(nextEvent);
        }
    }

    return 0;
}