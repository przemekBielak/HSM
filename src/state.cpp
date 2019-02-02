#include "state.hpp"
#include <iostream>

State::State() {
    /* Reserve vector size to avoid dynamic memory allocation (vector resizing). */
    transition.reserve(MAX_NUM_OF_TRANSITIONS);
}

State::State(State *parent_, void(*handler_)()) {
    parent = parent_;
    handler = handler_;
    transition.reserve(MAX_NUM_OF_TRANSITIONS);
}


State *State::getParent() {
    return parent;
}


handler State::getHandler() {
    return handler;
}


int State::addTransition(struct transition_t_ tr) {
    int ret = 0;

    /* Return error if transition with event tr already exists. */
    for(auto const& i: transition) {
        std::cout << i.event << std::endl;
        if(i.event == tr.event) {
            ret = -1;
        }
    }

    if(ret == 0) {
        transition.push_back(tr);
    }

    return ret;
}


std::vector<struct transition_t_> State::getTransition(void) {
    return transition;
}