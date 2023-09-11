/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:48
 * @ Modified by: Samael
 * @ Modified time: 2023-09-12 08:23:44
 * @ Description:
 */

#include "Nurse.hpp"

Nurse::Nurse(std::string const &name) : _name(name)
{
    std::cout << "Nurse " << _name << " created" << std::endl;
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