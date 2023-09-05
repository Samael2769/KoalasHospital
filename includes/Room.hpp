/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:34
 * @ Modified by: Samael
 * @ Modified time: 2023-09-05 21:28:50
 * @ Description:
 */

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
#include "Doctor.hpp"

class Room {
    public:
        Room(int id);
        ~Room();
    protected:
    private:
        int _id;
};

#endif /* !ROOM_HPP */