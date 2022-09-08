/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Doctor
*/

#ifndef DOCTOR_HPP_
#define DOCTOR_HPP_

#include "Patient.hpp"

//Threads in Rooms
class Doctor {
    public:
        Doctor(std::string name);
        ~Doctor();
        void diagnose(Patient * patient);
        void update();
    protected:
    private:
        std::string name;
        int timer;
        Patient * patient;
        bool isAvailable;
};

#endif /* !DOCTOR_HPP_ */
