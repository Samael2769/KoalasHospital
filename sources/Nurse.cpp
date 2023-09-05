/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:48
 * @ Modified by: Samael
 * @ Modified time: 2023-09-05 22:07:35
 * @ Description:
 */

#include "Nurse.hpp"

Nurse::Nurse(std::string const &name) : _name(name)
{
}

Nurse::~Nurse()
{
}

std::string const &Nurse::getName() const
{
    return (_name);
}

void Nurse::setName(std::string const &name)
{
    _name = name;
}

void Nurse::giveDrug(symptoms_t symp, Patient &patient) const
{
    patient.takeDrug(symp);
}