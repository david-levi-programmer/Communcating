#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

Connection server;

std::string messageSent;
std::string messageReceived;

int main(int argc, char* argv[])
{
    server.Initaialize();
    server.OpenSocket();
    server.ListenSocket();
    
    while (messageSent != "end" && messageReceived != "end")
    {
        server.Send(messageSent);
        server.Receive(messageReceived);
    }

    server.CloseSocket();
    server.ShutDown();
    
    system("pause");
    return 0;
}