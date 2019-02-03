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


StateMachine::StateMachine(State * const initState) {
    m_currState = initState;
}


State *StateMachine::getCurrState() {
    return m_currState;
}


bool StateMachine::run(const event_t event) {
    bool searching = true;
    bool found = false;
    State *st = m_currState;

    while(searching) {
        for(auto const& tr: st->getTransition()) {
            if(tr.event == event) {
                /* Stop searching, found */
                searching = false;
                found = true;
                m_currState = tr.nextState;
                m_currState->getHandler()();
            }
        }
        
        st = st->getParent();
        /* Check if state has a parent */
        if(st == nullptr) {
            /* Stop searching, not found */
            searching = false;
        }
    };

    return found;
}
