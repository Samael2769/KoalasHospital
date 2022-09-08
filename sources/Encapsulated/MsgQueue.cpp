/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** MsgQueue
*/

#include "MsgQueue.hpp"
#include <iostream>
#include <cstring>

MsgQueue::MsgQueue(std::string key)
{
    this->key = ftok(key.c_str(), 65);
    this->msgid = msgget(this->key, 0666 | IPC_CREAT);
}

MsgQueue::~MsgQueue()
{
}

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

void MsgQueue::send(std::string msg)
{
    message.mesg_type = 1;
    strcpy(message.mesg_text, msg.c_str());
    msgsnd(this->msgid, &message, sizeof(message), 0);
}

std::string MsgQueue::receive()
{   
    if (msgrcv(this->msgid, &message, sizeof(message), 1, IPC_NOWAIT) != -1) {
        std::string msg = message.mesg_text;
        return msg;
    } else
        return "NULL";
}