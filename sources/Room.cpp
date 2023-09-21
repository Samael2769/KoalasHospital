/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:05:08
 * @ Modified by: Samael
 * @ Modified time: 2023-09-22 07:51:14
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
            _graphics->deletePeople(_patients[0].getName(), "Patient", "Room " + std::to_string(_id));
            _graphics->addText(_patients[0].getName() + " has been vaccinated", "Room " + std::to_string(_id));
            _patients.erase(_patients.begin());
            return;
        } else
            _graphics->addText(_patients[0].getName() + "'s vaccination failed", "Room " + std::to_string(_id));
        symptoms_t symp = _doctors[0].diagnose(_patients[0], _knownSymptoms);
        if (_nurses[0].giveDrug(symp, _patients[0]) == true) {  
            _graphics->deletePeople(_patients[0].getName(), "Patient", "Room " + std::to_string(_id));
            _graphics->addText(_patients[0].getName() + " has been cured", "Room " + std::to_string(_id));
            _patients.erase(_patients.begin());
            std::cout << "Room " << _id << ": Patient cured" << std::endl;
        } else {
            _graphics->addText(_patients[0].getName() + "'s drug failed", "Room " + std::to_string(_id));
            bool isDead = _patients[0].pingLife();
            if (isDead == false) {
                _graphics->deletePeople(_patients[0].getName(), "Patient", "Room " + std::to_string(_id));
                _graphics->addText(_patients[0].getName() + " died", "Room " + std::to_string(_id));
                _patients.erase(_patients.begin());
                std::cout << "Room " << _id << ": Patient died" << std::endl;
            }
        }
    }
}

void Room::addPatient(Patient &patient)
{
    _patients.push_back(patient);
    _graphics->createPeople(patient.getName(), "Patient", "Room " + std::to_string(_id), 0, 0);
    _graphics->addText(patient.getName() + " arrived", "Room " + std::to_string(_id));
    std::cout << "Room " << _id << ": Patient " << patient.getName() << " arrived" << std::endl;
}

void Room::setGraphics(Graphics *graphics)
{
    _graphics = graphics;
}