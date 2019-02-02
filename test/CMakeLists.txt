
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

include_directories (${HSM_SOURCE_DIR}/src) 

add_executable(
    runTests 
    main.cpp
    stateMachineTest.cpp
    stateTest.cpp
)

target_link_libraries(
    runTests 
    StateMachine
)