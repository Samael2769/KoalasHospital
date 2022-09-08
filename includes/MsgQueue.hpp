/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** MsgQueue
*/

#ifndef MSGQUEUE_HPP_
#define MSGQUEUE_HPP_

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>

class MsgQueue {
    public:
        MsgQueue(std::string key);
        ~MsgQueue();
        void send(std::string msg);
        std::string receive();
    protected:
    private:
        key_t key;
        int msgid;
};

#endif /* !MSGQUEUE_HPP_ */
