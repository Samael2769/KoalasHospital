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
};

#endif /* !KOALAHOSPITAL_HPP_ */
