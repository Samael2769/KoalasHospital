/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Nurse
*/

#ifndef NURSE_HPP_
#define NURSE_HPP_

#include "Patient.hpp"

//Threads in Rooms
class Nurse {
    public:
        Nurse(std::string name);
        ~Nurse();
        void heal(Patient * patient);
        void update();
    protected:
    private:
        int timer;
        Patient * patient;
        bool isAvailable;
        std::string name;
};

#endif /* !NURSE_HPP_ */