/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Hospital
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include "Rooms.hpp"

class Hospital {
    public:
        Hospital();
        ~Hospital();
        void run();
        void addRooms();
    protected:
    private:
        std::vector<Patient> patients;
        float timer;
        std::vector<Rooms> rooms;
        int turns;
};

#endif /* !HOSPITAL_HPP_ */
