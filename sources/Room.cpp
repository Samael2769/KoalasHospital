/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:05:08
 * @ Modified by: Samael
 * @ Modified time: 2023-09-12 08:22:59
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
    std::cout << "Room " << _id << " running" << std::endl;
    while (true) {
        usleep(1000000);
        std::cout << "Room " << _id << " waiting for patient" << std::endl;
    }
}