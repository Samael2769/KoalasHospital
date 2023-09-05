/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** KoalaHospital
*/

#ifndef KOALAHOSPITAL_HPP_
#define KOALAHOSPITAL_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Room.hpp"

class KoalaHospital {
    public:
        KoalaHospital();
        ~KoalaHospital();
    protected:
    private:
        std::vector<symptoms_t> knownSymptoms;
};

#endif /* !KOALAHOSPITAL_HPP_ */
