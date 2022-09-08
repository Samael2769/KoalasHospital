/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Rooms
*/

#ifndef ROOMS_HPP_
#define ROOMS_HPP_

#include <vector>
#include "Doctor.hpp"
#include "Nurse.hpp"
#include "Fork.hpp"
#include "MsgQueue.hpp"
#include <unistd.h>
#include <stdio.h>

//Forks
class Rooms {
    public:
        Rooms(int id);
        ~Rooms();
        void run();
    protected:
    private:
        int id;
        Fork * fork;
        MsgQueue * msgQueue;
        std::vector<Doctor> doctors;
        std::vector<Nurse> nurses;
        std::vector<Patient> patients;
};

#endif /* !ROOMS_HPP_ */