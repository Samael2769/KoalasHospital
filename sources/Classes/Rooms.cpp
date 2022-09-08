/*
** EPITECH PROJECT, 2022
** *
** File description:
** Rooms
*/

#include "Rooms.hpp"

int forkFct(void *data)
{
    std::string *key = (std::string *)data;
    std::cout << *key << std::endl;
    MsgQueue msg(*key);
    int timer = (clock() / CLOCKS_PER_SEC) + 1;
    int f_time = 0;
    while(1) {
        if (timer < (clock() / CLOCKS_PER_SEC)) {
            timer = (clock() / CLOCKS_PER_SEC) + 1;
            f_time ++;
        }
        std::string message = msg.receive();
        if (message == "NULL" && f_time % 2 == 0 && f_time != 0) {
            std::cout << "NULL" << std::endl;
            break;
        }
        std::cout << "Hello" << std::endl;
    }
    return 0;
}

Rooms::Rooms(int id)
{
    this->id = id;
    std::string * key = new std::string(std::to_string(id));
    this->fork = new Fork((void *)key, &forkFct, false);
    fork->setData((void *)key);
    this->msgQueue = new MsgQueue(*key);
}

Rooms::~Rooms()
{
}

void Rooms::run()
{
    fork->process();
}
