project(strategies)
set(SOURCES
        human.cpp
        computer_strategy_1.cpp
        computer_strategy_2.cpp
        computer_interface.cpp)
set(HEADERS
        human.h
        computer_strategy_1.h
        computer_strategy_2.h
        interface.h
        computer_interface.h)

include_directories(../)

add_library(strategies ${SOURCES} ${HEADERS})