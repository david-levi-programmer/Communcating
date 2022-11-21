#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

Connection server;

std::string messageSent;
std::string messageReceived;

bool isRunning = true;

int main(int argc, char* argv[])
{
    server.Initaialize();
    server.OpenSocket();
    server.ListenSocket();
    
    while (isRunning)
    {
        server.Send(std::ref(messageSent));
        server.Receive(std::ref(messageReceived));
    }

    server.CloseSocket();
    server.ShutDown();
    
    system("pause");
    return 0;
}