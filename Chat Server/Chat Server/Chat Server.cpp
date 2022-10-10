#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

#define MAX_SOCKETS 0x10

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
        std::cout << "Enter your message: ";
        std::cin >> messageSent;
        server.Send(messageSent);
    }

    system("pause");
    return 0;

    server.ShutDown();
}