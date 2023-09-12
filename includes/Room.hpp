/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:34
 * @ Modified by: Samael
 * @ Modified time: 2023-09-13 07:08:33
 * @ Description:
 */

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
#include "Doctor.hpp"

class Room {
    public:
        Room(int id);
        ~Room();
        void run();
        void addPatient(Patient &patient);
    protected:
    private:
        int _id;
        std::vector<Doctor> _doctors;
        std::vector<Patient> _patients;
        std::vector<Nurse> _nurses;
};

#endif /* !ROOM_HPP */