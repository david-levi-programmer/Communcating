#include <iostream>
#include <string>
#include <thread>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"
#define CHAT_PROMPT "/"

Connection client;

std::string messageSent;
std::string messageReceived;

int main(int argc, char* argv[])
{
    client.Initaialize();
    client.OpenSocket();

    while (messageSent != "end" && messageReceived != "end")
    {
        std::thread talk(&Connection::Send, Connection(), messageSent);
        std::thread hear(&Connection::Receive, Connection(), messageReceived);
    }

    system("pause");
    return 0;
    
    client.ShutDown();
}