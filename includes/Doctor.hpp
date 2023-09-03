/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:12
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:24:50
 * @ Description:
 */

#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <iostream>
#include <string>
#include "Patient.hpp"

class Doctor {
    public:
        Doctor(std::string const &name);
        ~Doctor();
        std::string const &getName() const;
        void setName(std::string const &name);
        void diagnose(Patient const &patient) const;
    protected:
    private:
        std::string _name;
};

#endif /* !DOCTOR_HPP */s