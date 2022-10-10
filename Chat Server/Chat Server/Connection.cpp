#include "Connection.h"
#include <iostream>
#include <string>

TCPsocket listenSocket = nullptr;
TCPsocket clientSocket = nullptr;

//go into command prompt and type 'ipconfig' to see your address
//host and port number
const int port = 1234;

bool Connection::Initaialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL did not initialize properly." << std::endl;
        system("pause");
        return 0;
    }

    else if (SDLNet_Init() == -1)
    {
        std::cout << "Networking sub-system did not initialize properly." << std::endl;
        system("pause");
        return 0;
    }

    //setup with specific port number
    //as host, we use nullptr
    if (SDLNet_ResolveHost(&m_IP, nullptr, port) == -1)
    {
        std::cout << "Could not create server" << std::endl;
        system("pause");
        return 0;
    }
}

bool Connection::OpenSocket()
{
    //if server created above, open listen socket
    listenSocket = SDLNet_TCP_Open(&m_IP);

    if (!listenSocket)
    {
        std::cout << "Could not open listening socket" << std::endl << std::endl;
        system("pause");
        return 0;
    }

    std::cout << "Socket open for clients." << std::endl << std::endl;
    std::cout << "Waiting for client." << std::endl;
}

void Connection::ListenSocket()
{
    //listen for client with small delay so that CPU isn't overworked
    //when connection made, save it in new socket and remove old one
    while (!clientSocket)
    {
        clientSocket = SDLNet_TCP_Accept(listenSocket);
        std::cout << ".";
        SDL_Delay(500);
    }
    
    SDLNet_TCP_Close(listenSocket); //realistically, you would be waiting for more connections
    std::cout << std::endl << "Client connected" << std::endl << std::endl;
}

bool Connection::Send(const std::string& message)
{
    std::cout << "Message sent";
    return true;
}

bool Connection::Receive(std::string& message)
{
    return true;
}

void Connection::CloseSocket()
{

}

void Connection::ShutDown()
{
    SDLNet_Quit();
    SDL_Quit();
}