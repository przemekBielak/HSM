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


State::State(State *parent_, void(*handler_)()) {
    parent = parent_;
    handler = handler_;
    /* Reserve vector size to avoid dynamic memory allocation (vector resizing). */
    transition.reserve(MAX_NUM_OF_TRANSITIONS);
}


State *State::getParent() {
    return parent;
}


handler State::getHandler() {
    return handler;
}


stateError_t State::addTransition(struct transition_t_ tr) {
    stateError_t err = NO_ERROR;

    /* Return error if transition vector is full. No new transition will be added. */
    if(transition.size() >= MAX_NUM_OF_TRANSITIONS) {
        err = TRANSITION_QUEUE_FULL;
    }

    /* Return error if transition with event tr already exists. */
    for(auto const& i: transition) {
        if(i.event == tr.event) {
            err = TRANSITION_ALREADY_EXISTS;
        }
    }

    if(err == NO_ERROR) {
        transition.push_back(tr);
    }

    return err;
}


std::vector<struct transition_t_> State::getTransition(void) {
    return transition;
}