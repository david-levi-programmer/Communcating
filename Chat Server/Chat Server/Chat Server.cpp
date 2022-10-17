#include <iostream>
#include <string>
#include <thread>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

#define CHAT_PROMPT "/"

#define MAX_SOCKETS 0x10

Connection server;

int main(int argc, char* argv[])
{
    server.Initaialize();
    server.OpenSocket();
    std::thread door(&Connection::ListenSocket, Connection());
    door.detach();
    
    //std::thread talk(&Connection::Send, Connection());
    //std::thread hear(&Connection::Receive, Connection());

    server.CloseSocket();
    system("pause");
    return 0;
    
    server.ShutDown();
}