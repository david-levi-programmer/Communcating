#include <iostream>
#include <string>
#include <thread>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

#define CHAT_PROMPT "/"

Connection client;

int main(int argc, char* argv[])
{
    client.Initaialize();
    client.OpenSocket();

    std::thread talk(&Connection::Send, Connection());
   // std::thread hear(&Connection::Receive, Connection());

    //client.CloseSocket();
    system("pause");
    return 0;
    
    client.ShutDown();
}