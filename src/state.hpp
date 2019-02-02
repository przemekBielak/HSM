#ifndef STATE_H
#define STATE_H

#include <vector>

typedef void (*handler)();
typedef struct transition_t_ transition_t;

/* Configures maximum number of possible transitions for one state. */
#define MAX_NUM_OF_TRANSITIONS   (4u)


typedef enum event_t_ {
    EV_NO_EVENT = 0u,
    EV_STARTUP,
    EV_SHUTDOWN,
    EV_START_PLAYING,
    EV_STOP_PLAYING,
    NUM_OF_EVENTS
}event_t;

/* Acts as a linked list of states.
* Each state has exactly one parent and 0-* transitions.
*/
class State {
    public:
        State();
        State(State *parent, void (*handler)());

        State *getParent();
        handler getHandler();
        std::vector<transition_t> getTransition(void);

        int addTransition(transition_t tr);

    private:
        State *parent;
        void(*handler)();
        /* Vector is used because of forward declaration of transition_t (impossible to define array this way).
         * Size of vector is restricted to MAX_NUM_OF_TRANSITIONS, so dynamic resizing is not possible. */
        std::vector<transition_t> transition;
};

typedef struct transition_t_ {
    event_t event;
    State *nextState;
}transition_t;


#endif // #ifndef STATE_H