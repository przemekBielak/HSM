/**
 * @file stateMachine.cpp
 * @author Przemyslaw Bielak (przemyslaw.bielak@protonmail.com)
 * @brief Implementation of StateMachine class.
 * @version 0.1
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "stateMachine.hpp"


StateMachine::StateMachine(State *initState) {
    currState = initState;
}


State *StateMachine::getCurrState() {
    return currState;
}


bool StateMachine::run(event_t ev) {
    bool searching = true;
    bool found = false;
    State *st = currState;

    while(searching) {
        for(auto const& tr: st->getTransition()) {
            if(tr.event == ev) {
                /* Stop searching, found */
                searching = false;
                found = true;
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

    return found;
}
