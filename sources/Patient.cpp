/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:42
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:13:03
 * @ Description:
 */

#include "Patient.hpp"

Patient::Patient(std::string const &name) : _name(name)
{
}

Patient::~Patient()
{
}

std::string const &Patient::getName() const
{
    return (_name);
}

void Patient::setName(std::string const &name)
{
    _name = name;
}

void Patient::takeDrug(std::string const &drug)
{
}

void Patient::takeDrug(Deases const &deases)
{
}
