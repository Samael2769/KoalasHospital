/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:54
 * @ Modified by: Samael
 * @ Modified time: 2023-09-19 10:50:29
 * @ Description:
 */

#include "Deases.hpp"
#include <cmath>

Deases::Deases(std::string const &name) : _name(name)
{
    int sympNb = rand() % 5 + 1;

    for (int i = 0; i < sympNb; i++)
        _symptoms.push_back(std::make_pair(static_cast<symptoms_t>(rand() % 10), false));
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

std::vector<std::pair<symptoms_t, bool>> const &Deases::getSymptoms() const
{
    return (_symptoms);
}

bool Deases::isCured() const
{
    for (auto &i : _symptoms)
        if (i.second == false)
            return (false);
    return (true);
}

bool Deases::checkSymptoms(std::vector<symptoms_t> symptoms)
{
    for (int i = 0; i < symptoms.size(); i++)
        for (int j = 0; j < _symptoms.size(); j++)
            if (symptoms[i] == _symptoms[j].first)
                _symptoms[j].second = true;
    return (isCured());
}

bool Deases::checkSymptoms(symptoms_t symptoms)
{
    for (int j = 0; j < _symptoms.size(); j++)
        if (symptoms == _symptoms[j].first) {
            _symptoms[j].second = true;
            return (true);
        }
    return (false);
}

