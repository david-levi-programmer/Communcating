#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

Connection client;

std::string messageSent;
std::string messageReceived;

bool isRunning = true;

int main(int argc, char* argv[])
{
    client.Initaialize();
    client.OpenSocket();

    while (isRunning)
    {
        client.Send(std::ref(messageSent));
        client.Receive(std::ref(messageReceived));
    }
    
    client.CloseSocket();
    client.ShutDown();

    system("pause");
    return 0;
}