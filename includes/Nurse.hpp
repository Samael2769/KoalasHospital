/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:03:56
 * @ Modified by: Samael
 * @ Modified time: 2023-09-14 22:07:41
 * @ Description:
 */

#ifndef NURSE_HPP
#define NURSE_HPP

#include <iostream>
#include <string>
#include "Patient.hpp"

class Nurse {
    public:
        Nurse(std::string const &name);
        ~Nurse();
        std::string const &getName() const;
        void setName(std::string const &name);
        bool giveDrug(symptoms_t symp, Patient &patient) const;
        bool giveVaccin(std::vector<symptoms_t> knownSymptoms, Patient &patient);
    protected:
    private:
        std::string _name;
};

#endif /* !NURSE_HPP */