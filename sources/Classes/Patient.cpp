/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Patient
*/

#include "Patient.hpp"

Patient::Patient(std::string name)
{
    this->name = name;
    isSick = true;
    isDead = false;
    death_timer = 50;
    act_remede = -1;
    int nb_deases = (rand() % 4) + 1;
    for (int i = 0; i < nb_deases; i++) {
        deases.push_back(Deases());
    }
}

Patient::~Patient()
{
}

void Patient::checkDeath()
{
    if (isSick == true) {
        death_timer -= 1;
        if (death_timer <= 0)
            isDead = true;
    }
}

void Patient::heal()
{
    if (isSick == true) {
        if (static_cast<Deases::Type>(act_remede) == deases[0].getType()) {
            deases.erase(deases.begin());
            if (deases.size() == 0)
                isSick = false;
        }
    }
}
