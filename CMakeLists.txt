cmake_minimum_required(VERSION 3.27)
project(AccessControlSystem C)

set(CMAKE_C_STANDARD 17)

add_executable(AccessControlSystem main.c
        display.c
        display.h
        utils.c
        utils.h
        door_man.c
        door_man.h
        records_op.c
        records_op.h
        card_man.c
        card_man.h
        resident_man.c
        resident_man.h)
