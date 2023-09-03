/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:03:49
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:13:12
 * @ Description:
 */

#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>
#include <string>
#include "Deases.hpp"

class Patient {
    public:
        Patient(std::string const &name);
        ~Patient();
        std::string const &getName() const;
        void setName(std::string const &name);
        void takeDrug(std::string const &drug);
        void takeDrug(Deases const &deases);
    protected:
    private:
        std::string _name;
        int _life;
};

#endif /* !PATIENT_HPP */