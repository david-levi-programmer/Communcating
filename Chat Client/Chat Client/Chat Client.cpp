#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

Connection client;

std::string messageSent;
std::string messageReceived;

int main(int argc, char* argv[])
{
    client.Initaialize();
    client.OpenSocket();

    while (messageSent != "end" && messageReceived != "end")
    {
        client.Send(std::ref(messageSent));
        client.Receive(std::ref(messageReceived));
    }

    client.ShutDown();

    system("pause");
    return 0;
}