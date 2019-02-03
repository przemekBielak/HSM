/**
 * @file stateMachine.hpp
 * @author Przemyslaw Bielak (przemyslaw.bielak@protonmail.com)
 * @brief Describes a state machine logic.
 * @version 0.1
 * @date 2019-02-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "state.hpp"

/**
 * @brief Adds logic and data between State elements
 * 
 */
class StateMachine {
    public:
        /**
         * @brief Construct a new State Machine object
         * 
         * @param initState Pointer to initial state
         */
        StateMachine(State * const initState);

        /**
         * @brief Get the current state object
         * 
         * @return State* 
         */
        State *getCurrState();

        /**
         * @brief Executes state machine transition (if possible)
         * 
         * @param ev Requested event. 
         * @return true     event found
         * @return false    event not found
         */
        bool run(const event_t event) ;

    private:
        /**
         * @brief Current state
         * 
         */
        State *m_currState;
};

#endif // #ifndef STATEMACHINE_H