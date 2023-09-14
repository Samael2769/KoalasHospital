/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:05:08
 * @ Modified by: Samael
 * @ Modified time: 2023-09-14 22:08:27
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
    if (_patients.size() > 0) {
        if (_nurses[0].giveVaccin(_knownSymptoms, _patients[0]) == true) {  
            _patients.erase(_patients.begin());
            std::cout << "Room " << _id << ": Patient cured" << std::endl;
        }
        symptoms_t symp = _doctors[0].diagnose(_patients[0], _knownSymptoms);
        if (_nurses[0].giveDrug(symp, _patients[0]) == true) {  
            _patients.erase(_patients.begin());
            std::cout << "Room " << _id << ": Patient cured" << std::endl;
        }
    }
}

void Room::addPatient(Patient &patient)
{
    _patients.push_back(patient);
    std::cout << "Room " << _id << ": Patient " << patient.getName() << " arrived" << std::endl;
}