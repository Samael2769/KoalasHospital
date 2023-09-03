/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:59
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:09:48
 * @ Description:
 */

#include "Doctor.hpp"

Doctor::Doctor(std::string const &name) : _name(name)
{
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

void Doctor::diagnose(Patient const &patient) const
{
}