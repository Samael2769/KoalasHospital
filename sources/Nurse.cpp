/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:48
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:11:38
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

void Nurse::giveDrug(std::string const &drug, Patient &patient) const
{
    patient.takeDrug(drug);
}

void Nurse::readReport(std::string const &report) const
{
}