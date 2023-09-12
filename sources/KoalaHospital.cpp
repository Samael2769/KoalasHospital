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
    for (int i = 0; i < nbRooms; i++) {
        std::thread *thread = new std::thread(&KoalaHospital::startThread, this);
        threads.push_back(thread);
        usleep(100);
        roomIndex++;
    }
    patients.push_back(Patient("Patient 1"));
    patients.push_back(Patient("Patient 2"));
    patients.push_back(Patient("Patient 3"));
    while (patients.size() > 0) {
        usleep(1000000);
        std::cout << "Patients waiting:" << std::endl;
        for (int i = 0; i < patients.size(); i++) {
            std::cout << patients[i].getName() << std::endl;
        }
    }
}

void KoalaHospital::startThread()
{
    std::cout << "Thread " << roomIndex << " created" << std::endl;
    Room room(roomIndex);
    while (true) {
        usleep(1000000);
        if (patients.size() > 0) {
            mutex.lock();
            room.addPatient(patients[0]);
            patients.erase(patients.begin());
            mutex.unlock();
        }
        room.run(); 
    }
}