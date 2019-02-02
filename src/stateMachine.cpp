#include "stateMachine.hpp"


StateMachine::StateMachine(State *initState) {
    currState = initState;
}


State *StateMachine::getCurrState() {
    return currState;
}


void StateMachine::run(event_t ev) {
    bool searching = true;
    State *st = currState;

    while(searching) {
        for(auto const& tr: st->getTransition()) {
            if(tr.event == ev) {
                /* Stop searching, found */
                searching = false;
                currState = tr.nextState;
                currState->getHandler()();
            }
        }
        
        st = st->getParent();
        /* Check if state has a parent */
        if(st == NULL) {
            /* Stop searching, not found */
            searching = false;
        }
    };
}
