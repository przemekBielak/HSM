if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wold-style-cast -Wunused -Wconversion -Wnull-dereference -Wconversion -Wsign-conversion")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_library(
    StateMachine 
    stateMachine.cpp 
    stateMachine.hpp
    state.cpp
    state.hpp
    state_cfg.hpp
)

add_executable(
    out 
    main.cpp
)

target_link_libraries(
    out 
    StateMachine
)

