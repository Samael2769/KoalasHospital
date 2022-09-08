/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Patient
*/

#ifndef PATIENT_HPP_
#define PATIENT_HPP_

#include <Deases.hpp>
#include <vector>

//Tab of Patients sent to the Rooms
class Patient {
    public:
        Patient(std::string name);
        ~Patient();
        std::string getName() { return name; }
        std::vector<Deases> getDeases() { return deases; }
        void checkDeath();
        bool getDeath() { return isDead; }
        void heal();
        void setRemede(int remede) { this->act_remede = remede; }
    protected:
    private:
        std::vector<Deases> deases;
        bool isDead;
        bool isSick;
        float death_timer;
        std::string name;
        int act_remede;
};

#endif /* !PATIENT_HPP_ */
