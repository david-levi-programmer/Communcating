#include <iostream>
#include <string>
#include <thread>
#include <SDL.h>
#include <SDL_net.h>
#include "Connection.h"

#define CHAT_PROMPT "/"

#define MAX_SOCKETS 0x10

Connection server;

std::string messageSent;
std::string messageReceived;

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
    
    system("pause");
    return 0;

    server.CloseSocket();
    server.ShutDown();
}