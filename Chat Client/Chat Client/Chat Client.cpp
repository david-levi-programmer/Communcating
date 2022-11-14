#include <iostream>
#include <string>
#include <thread>
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

    //TODO - this should be in a loop
    //std::thread talk(&Connection::Send, Connection(), std::ref(messageSent));
    //std::thread hear(&Connection::Receive, Connection(), std::ref(messageReceived));
    client.Receive(std::ref(messageReceived));
    client.Send(std::ref(messageSent));

    system("pause");
    return 0;
    
    client.CloseSocket();
    client.ShutDown();
}