#include <iostream>
#include <string>
#include <thread>
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

    client.Send(std::ref(messageSent));
    client.Receive(std::ref(messageReceived));
    
    //std::thread talk(&Connection::Send, Connection(), std::ref(messageSent));
    //std::thread hear(&Connection::Receive, Connection(), std::ref(messageReceived));
    /*if (isRunning)
    {
        client.Receive(std::ref(messageReceived));
        client.Send(std::ref(messageSent));
    }
    else
    {
        isRunning = false;
    }*/
    
    client.CloseSocket();
    client.ShutDown();

    system("pause");
    return 0;
}