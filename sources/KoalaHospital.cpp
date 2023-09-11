/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** KoalaHospital
*/

#include "KoalaHospital.hpp"
#include "cmath"
#include <unistd.h>

KoalaHospital::KoalaHospital()
{
    nbRooms = 2;
    roomIndex = 0;
}

KoalaHospital::~KoalaHospital()
{
    
}

void KoalaHospital::run()
{
    for (int i = 0; i < nbRooms; i++) {
        std::thread *thread = new std::thread(&KoalaHospital::startThread, this);
        threads.push_back(thread);
        usleep(100);
        roomIndex++;
    }
    for (int i = 0; i < nbRooms; i++) {
        threads[i]->join();
    }
}

void KoalaHospital::startThread()
{
    std::cout << "Thread " << roomIndex << " created" << std::endl;
    Room room(roomIndex);
    room.run();
}