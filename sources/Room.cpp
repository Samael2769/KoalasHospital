/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:05:08
 * @ Modified by: Samael
 * @ Modified time: 2023-09-06 08:04:56
 * @ Description:
 */

#include "Room.hpp"

Room::Room(int id) : _id(id)
{
    std::cout << "Room " << _id << " created" << std::endl;
}

Room::~Room()
{
}