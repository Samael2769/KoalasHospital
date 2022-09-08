/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Deases
*/

#include "Deases.hpp"

Deases::Deases()
{
    type = static_cast<Type>(rand() % 4);
}

Deases::~Deases()
{
}
