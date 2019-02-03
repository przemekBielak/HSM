/**
 * @file state_cfg.hpp
 * @author Przemyslaw Bielak (przemyslaw.bielak@protonmail.com)
 * @brief Configuration of State class.
 * @version 0.1
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef STATE_CFG_H
#define STATE_CFG_H


/** @brief Configures maximum number of possible transitions for one state */
 #define MAX_NUM_OF_TRANSITIONS   (4u)


/** @brief Describes all possible events */
typedef enum event_t_ {
    EV_NO_EVENT = 0u,
    EV_STARTUP,
    EV_SHUTDOWN,
    EV_START_PLAYING,
    EV_STOP_PLAYING,
    NUM_OF_EVENTS
}event_t;


#endif // #ifndef STATE_CFG_H