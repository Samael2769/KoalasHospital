/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** KoalaHospital
*/

#include "KoalaHospital.hpp"
#include "cmath"
#include <unistd.h>
#include <time.h>

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
    Graphics graphics;
    _graphics = &graphics;
    for (int i = 0; i < nbRooms; i++) {
        std::thread *thread = new std::thread(&KoalaHospital::startThread, this);
        _graphics->createRoom("Room " + std::to_string(roomIndex), roomIndex, 0);
        threads.push_back(thread);
        usleep(100);
        roomIndex++;
    }
    patients.push_back(Patient("Patient 1"));
    patients.push_back(Patient("Patient 2"));
    patients.push_back(Patient("Patient 3"));
    _graphics->run();
    for (int i = 0; i < threads.size(); i++) {
        threads[i]->join();
    }
}

void KoalaHospital::startThread()
{
    std::cout << "Thread " << roomIndex << " created" << std::endl;
    Room room(roomIndex);
    room.setGraphics(_graphics);
    room.init();
    while (true) {
        usleep(1000000);
        mutex.lock();
        if (patients.size() > 0) {
            room.addPatient(patients[0]);
            patients.erase(patients.begin());
        }
        mutex.unlock();
        room.run(); 
    }
}