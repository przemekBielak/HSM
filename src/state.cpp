/**
 * @file state.cpp
 * @author Przemyslaw Bielak (przemyslaw.bielak@protonmail.com)
 * @brief Implementation of State class.
 * @version 0.1
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "state.hpp"
#include <iostream>


State::State(State * const parent, void(*handler)()) {
    m_parent = parent;
    m_handler = handler;
    /* Reserve vector size to avoid dynamic memory allocation (vector resizing). */
    m_transition.reserve(MAX_NUM_OF_TRANSITIONS);
}


State *State::getParent() {
    return m_parent;
}


handler State::getHandler() {
    return m_handler;
}


stateError_t State::addTransition(const transition_t transition) {
    stateError_t err = NO_ERROR;

    /* Return error if transition vector is full. No new transition will be added. */
    if(m_transition.size() >= MAX_NUM_OF_TRANSITIONS) {
        err = TRANSITION_QUEUE_FULL;
    }

    /* Return error if transition with event tr already exists. */
    for(auto const& i: m_transition) {
        if(i.event == transition.event) {
            err = TRANSITION_ALREADY_EXISTS;
        }
    }

    if(err == NO_ERROR) {
        m_transition.push_back(transition);
    }

    return err;
}


std::vector<struct transition_t_> State::getTransition(void) {
    return m_transition;
}