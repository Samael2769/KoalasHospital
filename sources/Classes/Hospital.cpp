/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Hospital
*/

#include "Hospital.hpp"
#include <iostream>

Hospital::Hospital()
{
    srand(time(NULL));
    timer = (clock() / CLOCKS_PER_SEC) + 1;
    this->turns = 0;
}

Hospital::~Hospital()
{
}

void Hospital::run()
{
    rooms.push_back(Rooms(1));
    while (1) {
        if (timer < (clock() / CLOCKS_PER_SEC)) {
            timer = (clock() / CLOCKS_PER_SEC) + 1;
            turns++;
        }
        rooms[0].run();
        break;
    }
}