/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:48
 * @ Modified by: Samael
 * @ Modified time: 2023-09-14 22:06:10
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

bool Nurse::giveDrug(symptoms_t symp, Patient &patient) const
{
    return patient.takeDrug(symp);
}

bool Nurse::giveVaccin(std::vector<symptoms_t> knownSymptoms, Patient &patient)
{
    return patient.checkKnownSymptoms(knownSymptoms);
}