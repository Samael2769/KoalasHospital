/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** KoalaHospital
*/

#ifndef KOALAHOSPITAL_HPP_
#define KOALAHOSPITAL_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <thread>
#include "Room.hpp"
#include <mutex>

class KoalaHospital {
    public:
        KoalaHospital();
        ~KoalaHospital();
        void run();
        void startThread();
    protected:
    private:
        int nbRooms;
        int roomIndex;
        std::vector<symptoms_t> knownSymptoms;
        std::vector<std::thread *> threads;
        std::vector<Patient> patients;
        //mutex
        std::mutex mutex;
        Graphics *_graphics;
};

#endif /* !KOALAHOSPITAL_HPP_ */
