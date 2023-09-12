/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:05:08
 * @ Modified by: Samael
 * @ Modified time: 2023-09-13 07:12:23
 * @ Description:
 */

#include "Room.hpp"
#include <unistd.h>

Room::Room(int id) : _id(id)
{
    std::cout << "Room " << _id << " created" << std::endl;
    _doctors.push_back(Doctor("Doctor 1"));
    _nurses.push_back(Nurse("Nurse 1"));
    _nurses.push_back(Nurse("Nurse 2"));
}

Room::~Room()
{
}

void Room::run()
{
    usleep(1000000);
    for (int i = 0; i < _patients.size(); i++) {
        std::cout << "Room " << _id << ": Patient " << _patients[i].getName() << " being treated" << std::endl;
    }
}

void Room::addPatient(Patient &patient)
{
    _patients.push_back(patient);
    std::cout << "Room " << _id << ": Patient " << patient.getName() << " arrived" << std::endl;
}