#include <iostream>
#include <string>
#include <thread>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

#define CHAT_PROMPT "/"

Connection client;

//std::string messageSent;

int main(int argc, char* argv[])
{
    client.Initaialize();
    client.OpenSocket();

    //std::thread talk(&Connection::Send, Connection());
    //std::thread hear(&Connection::Receive, Connection());

    system("pause");
    return 0;
    
    //client.CloseSocket();
    client.ShutDown();
}