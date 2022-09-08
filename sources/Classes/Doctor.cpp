/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Doctor
*/

#include "Doctor.hpp"

Doctor::Doctor(std::string name)
{
   timer = 5; 
   this->name = name;
}

Doctor::~Doctor()
{
}

void Doctor::diagnose(Patient * patient)
{
    this->patient = patient;
    isAvailable = false;
}

void Doctor::update()
{
    if (isAvailable == false) {
        timer -= 1;
        if (timer <= 0) {
            patient->setRemede(patient->getDeases()[0].getType());
            isAvailable = true;
            patient = nullptr;
            timer = 5;
        }
    }
}