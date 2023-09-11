/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:59
 * @ Modified by: Samael
 * @ Modified time: 2023-09-12 08:23:39
 * @ Description:
 */

#include "Doctor.hpp"

Doctor::Doctor(std::string const &name) : _name(name)
{
    std::cout << "Doctor " << _name << " created" << std::endl;
}

Doctor::~Doctor()
{
}

std::string const &Doctor::getName() const
{
    return (_name);
}

void Doctor::setName(std::string const &name)
{
    _name = name;
}

symptoms_t Doctor::diagnose(Patient &patient, std::vector<symptoms_t> knownSymptoms) const
{
    patient.checkKnownSymptoms(knownSymptoms);
    symptoms_t symp = static_cast<symptoms_t>(rand() % 10);
    std::cout << "Doctor " << _name << " diagnosed " << patient.getName() << " with " << symp << std::endl;
    return (symp);
}