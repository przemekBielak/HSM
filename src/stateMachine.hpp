#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "state.hpp"


class StateMachine {
    public:
        StateMachine(State *initState);
        State *getCurrState();

        bool run(event_t ev) ;

    private:
        State *currState;
};

#endif // #ifndef STATEMACHINE_H