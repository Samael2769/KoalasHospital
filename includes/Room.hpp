/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:34
 * @ Modified by: Samael
 * @ Modified time: 2023-09-20 07:56:40
 * @ Description:
 */

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
#include "Doctor.hpp"
#include "Graphics.hpp"

class Room {
    public:
        Room(int id);
        ~Room();
        void run();
        void addPatient(Patient &patient);
        void setGraphics(Graphics *graphics);
        void init();
    protected:
    private:
        int _id;
        std::vector<Doctor> _doctors;
        std::vector<Patient> _patients;
        std::vector<Nurse> _nurses;
        std::vector<symptoms_t> _knownSymptoms;
        Graphics *_graphics;
};

#endif /* !ROOM_HPP */