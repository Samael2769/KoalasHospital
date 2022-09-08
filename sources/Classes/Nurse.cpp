/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Nurse
*/

#include "Nurse.hpp"

Nurse::Nurse(std::string name)
{
   timer = 5; 
   this->name = name;
}

Nurse::~Nurse()
{
}

void Nurse::heal(Patient * patient)
{
    this->patient = patient;
    isAvailable = false;
}

void Nurse::update()
{
    if (isAvailable == false) {
        timer -= 1;
        if (timer <= 0) {
            patient->heal();
            isAvailable = true;
            patient = nullptr;
            timer = 5;
        }
    }
}