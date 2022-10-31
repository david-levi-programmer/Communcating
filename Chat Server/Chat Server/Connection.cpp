#include "Connection.h"
#include <iostream>
#include <string>

//go into command prompt and type 'ipconfig' to see your address
//host and port number
const int port = 1234;

bool Connection::Initaialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL did not initialize properly." << std::endl;
        system("pause");
        return false;
    }

    else if (SDLNet_Init() == -1)
    {
        std::cout << "Networking sub-system did not initialize properly." << std::endl;
        system("pause");
        return false;
    }

    //setup with specific port number
    //as host, we use nullptr
    if (SDLNet_ResolveHost(&m_IP, nullptr, port) == -1)
    {
        std::cout << "Could not create server" << std::endl;
        system("pause");
        return false;
    }

    /*while (m_totalClients < MAX_CLIENTS)
    {
        while (!ListenSocket())
        {
            std::cout << "Waiting for clients..." << std::endl;
        }

        m_totalClients++;
    }*/
    return true;
}

bool Connection::OpenSocket()
{
    //if server created above, open listen socket
    m_listenSocket = SDLNet_TCP_Open(&m_IP);

    if (!m_listenSocket)
    {
        std::cout << "Could not open listening socket" << std::endl << std::endl;
        system("pause");
        return false;
    }

    std::cout << "Socket open for clients." << std::endl << std::endl;
    std::cout << "Waiting for client." << std::endl;
    return true;
}

bool Connection::ListenSocket()
{
    while (m_totalClients < MAX_CLIENTS)
    {
        TCPsocket tempSocket = nullptr;
    
        //when connection made, save it in new socket
        tempSocket = SDLNet_TCP_Accept(m_listenSocket);
        
        //if there's no client, pause for a bit then try again
        if (!tempSocket)
        {
            std::cout << "Waiting for clients...";
            SDL_Delay(500);
        }
        
        else
        {
            //otherwise store the connection for later
            m_clientSocket = tempSocket;
            std::cout << std::endl << "Client connected" << std::endl << std::endl;
            m_totalClients++;
        }

    }
    return true;
}

bool Connection::Send(/*const std::string& message*/)
{
    std::string messageSent;
    std::cin >> messageSent;
    int length = messageSent.length() + 1;
    if (SDLNet_TCP_Send(m_clientSocket, messageSent.c_str(), length) < length)
    {
        std::cout << "Couldn't send message" << std::endl;
    }
    std::cout << "Message sent." << std::endl;
    while (messageSent != "end")
    {
        return true;
    }

    return false;
}

bool Connection::Receive(std::string& message)
{
    std::string messageReceived;
    while (messageReceived != "end")
    {
        return true;
    }
    return false;
}

void Connection::CloseSocket()
{
    SDLNet_TCP_Close(m_listenSocket);
    std::cout << "Connection closed." << std::endl;
}

void Connection::ShutDown()
{
    SDLNet_Quit();
    SDL_Quit();
}