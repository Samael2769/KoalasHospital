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
    srand(time(NULL));
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
    std::thread *patient_thread = new std::thread(&KoalaHospital::patientThread, this);
    _graphics->run();
    for (int i = 0; i < threads.size(); i++) {
        threads[i]->join();
    }
    patient_thread->join();
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

void KoalaHospital::patientThread()
{
    while (true) {
        usleep(1000000);
        mutex.lock();
        if (rand() % 100 < 10) {
            Patient patient("Patient " + std::to_string(rand() % 10000));
            patients.push_back(patient);
        }
        mutex.unlock();
    }
}