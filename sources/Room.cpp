/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:05:08
 * @ Modified by: Samael
 * @ Modified time: 2023-09-20 07:57:12
 * @ Description:
 */

#include "Room.hpp"
#include <unistd.h>

Room::Room(int id) : _id(id)
{
    std::cout << "Room " << _id << " created" << std::endl;
}

void Room::init()
{
    _doctors.push_back(Doctor("Doctor 1"));
    _graphics->createPeople(_doctors[0].getName(), "Doctor", "Room " + std::to_string(_id), 0, 0);
    _nurses.push_back(Nurse("Nurse 1"));
    _nurses.push_back(Nurse("Nurse 2"));
    for (int i = 0; i < _nurses.size(); i++) {
        _graphics->createPeople(_nurses[i].getName(), "Nurse", "Room " + std::to_string(_id), 0, 0);
    }
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
            std::cout << "Room " << _id << ": Patient vaccined" << std::endl;
            return;
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
    _graphics->createPeople(patient.getName(), "Patient", "Room " + std::to_string(_id), 0, 0);
    std::cout << "Room " << _id << ": Patient " << patient.getName() << " arrived" << std::endl;
}

void Room::setGraphics(Graphics *graphics)
{
    _graphics = graphics;
}