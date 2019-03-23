/**
 * @file state.hpp
 * @author Przemyslaw Bielak (przemyslaw.bielak@protonmail.com)
 * @brief Describes a single state in a state machine.
 * @version 0.1
 * @date 2019-02-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef STATE_H
#define STATE_H

#include <vector>
#include "state_cfg.hpp"

/** @brief Pointer to a handler function */
typedef void (*handler)();
typedef struct transition_t_ transition_t;


/** @brief State class error codes */
typedef enum stateError_t_ {
    NO_ERROR = 0u,
    TRANSITION_QUEUE_FULL,
    TRANSITION_ALREADY_EXISTS
}stateError_t;


/**
 * @brief State is a node in linked list of states
 * @details Each state has exactly one parent and 0-* transitions
 */
class State {
    public:
        /**
         * @brief Construct a new State object
         * 
         * @param parent pointer to a parent state
         * @param handler function which is called when state is active
         */
        State(State * const parent, handler);

        ~State();

        /**
         * @brief Get the Parent object
         * 
         * @return State* 
         */
        State *getParent();

        /**
         * @brief Get the handler function
         * 
         * @return handler 
         */
        handler getHandler();

        /**
         * @brief Get the list of all transitions
         * 
         * @return std::vector<transition_t> 
         */
        std::vector<transition_t> getTransition(void);

        /**
         * @brief Add new transition 
         * 
         * @param tr transition 
         * @return stateError_t 
         */
        stateError_t addTransition(const transition_t transition);

    private:
        /** @brief Pointer to a parent state */
        State *m_parent;

        /** @brief Handler function */
        void(*m_handler)();

        /**
         * @brief Transition list
         * @details Vector is used because of forward declaration of transition_t (impossible to define array this way).
         * Size of vector is restricted to MAX_NUM_OF_TRANSITIONS, so dynamic resizing is not possible.
         * 
         */
        std::vector<transition_t> m_transition;
};

/**
 * @brief Describes state transition data
 * 
 */
typedef struct transition_t_ {
    event_t event;      /**< Event which starts the transition */
    State *nextState;   /**< Pointer to the next state */
}transition_t;


#endif // #ifndef STATE_H