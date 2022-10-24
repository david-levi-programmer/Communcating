#include <iostream>
#include <string>
#include <thread>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

#define CHAT_PROMPT "/"

#define MAX_SOCKETS 0x10

Connection server;

//std::string messageSent;

int main(int argc, char* argv[])
{
    server.Initaialize();
    server.OpenSocket();
    std::thread door(&Connection::ListenSocket, Connection());
    door.join();
    
    //std::thread talk(&Connection::Send, Connection());
    //std::thread hear(&Connection::Receive, Connection());
    
    system("pause");
    return 0;

    server.CloseSocket();
    server.ShutDown();
}