#include <iostream>
#include <string>
#include <thread>
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
    /*std::thread door(&Connection::ListenSocket, Connection());
    door.join();*/
    
    server.Send(std::ref(messageSent));
    server.Receive(std::ref(messageReceived));
    
    /*std::thread talk(&Connection::Send, Connection(), std::ref(messageSent));
    talk.detach();*/
    //std::thread hear(&Connection::Receive, Connection(), std::ref(messageReceived));
    /*if (isRunning)
    {
        server.Send(std::ref(messageSent));
        server.Receive(std::ref(messageReceived));
    }
    else
    {
        isRunning = false;
    }*/

    server.CloseSocket();
    server.ShutDown();
    
    system("pause");
    return 0;
}