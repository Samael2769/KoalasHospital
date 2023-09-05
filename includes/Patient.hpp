/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:03:49
 * @ Modified by: Samael
 * @ Modified time: 2023-09-05 22:16:58
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
        bool takeDrug(symptoms_t symp);
        void checkKnownSymptoms(std::vector<symptoms_t> knownSymptoms);
    protected:
    private:
        std::string _name;
        int _life;
        Deases *_deases;
};

#endif /* !PATIENT_HPP */