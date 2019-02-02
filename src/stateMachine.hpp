#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "state.hpp"


typedef void (*func)();


class StateMachine {
    public:
        StateMachine(State *initState);
        State *getCurrState();

        void run(event_t ev) ;

    private:
        State *currState;
};

#endif // #ifndef STATEMACHINE_H