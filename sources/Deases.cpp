/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:54
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:06:19
 * @ Description:
 */

#include "Deases.hpp"

Deases::Deases(std::string const &name) : _name(name)
{
}

Deases::~Deases()
{
}

std::string const &Deases::getName() const
{
    return (_name);
}

void Deases::setName(std::string const &name)
{
    _name = name;
}