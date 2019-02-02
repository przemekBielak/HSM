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

typedef void (*handler)();
typedef struct transition_t_ transition_t;


/** @brief Configures maximum number of possible transitions for one state. */
 #define MAX_NUM_OF_TRANSITIONS   (4u)


/** @brief Describes all possible events. */
typedef enum event_t_ {
    EV_NO_EVENT = 0u,
    EV_STARTUP,
    EV_SHUTDOWN,
    EV_START_PLAYING,
    EV_STOP_PLAYING,
    NUM_OF_EVENTS
}event_t;


/**
 * @brief State is a node in linked list of states.
 * @details Each state has exactly one parent and 0-* transitions.
 */
class State {
    public:
        /**
         * @brief Construct a new State object
         * 
         */
        State();

        /**
         * @brief Construct a new State object
         * 
         * @param parent pointer to a parent state
         * @param handler function which is called when state is active
         */
        State(State *parent, void (*handler)());

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
         * @return int 
         * @retval  0 OK
         * @retval -1 NOK
         */
        int addTransition(transition_t tr);

    private:
        /** @brief Pointer to a parent state */
        State *parent;

        /** @brief Handler function */
        void(*handler)();

        /**
         * @brief Transition list
         * @details Vector is used because of forward declaration of transition_t (impossible to define array this way).
         * Size of vector is restricted to MAX_NUM_OF_TRANSITIONS, so dynamic resizing is not possible.
         * 
         */
        std::vector<transition_t> transition;
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