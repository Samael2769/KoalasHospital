/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:03:56
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:07:47
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
        void giveDrug(std::string const &drug, Patient &patient) const;
        void readReport(std::string const &report) const;
    protected:
    private:
        std::string _name;
};

#endif /* !NURSE_HPP */