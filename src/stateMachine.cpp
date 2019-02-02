#include "stateMachine.hpp"


StateMachine::StateMachine(State *initState) {
    currState = initState;
}


State *StateMachine::getCurrState() {
    return currState;
}


void StateMachine::run(event_t ev) {

}
