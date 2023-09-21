/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:42
 * @ Modified by: Samael
 * @ Modified time: 2023-09-22 08:01:02
 * @ Description:
 */

#include "Patient.hpp"

Patient::Patient(std::string const &name) : _name(name)
{
    _deases = new Deases("Covid-19");
    _life = 10;
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

bool Patient::takeDrug(symptoms_t symp)
{
    _deases->checkSymptoms(symp);
    for (auto symps : _deases->getSymptoms()) {
        std::cout << symps.first << " : " << symps.second << std::endl;
    }
    if (_deases->isCured()) {
        std::cout << _name << " has been cured" << std::endl;
        return (true);
    } else {
        std::cout << _name << " is still sick" << std::endl;
        _life--;
        return (false);
    }
}

bool Patient::checkKnownSymptoms(std::vector<symptoms_t> knownSymptoms)
{
    return _deases->checkSymptoms(knownSymptoms);
}
