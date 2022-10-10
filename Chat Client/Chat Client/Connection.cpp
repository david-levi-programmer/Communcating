#include "Connection.h"

TCPsocket listenSocket = nullptr;
TCPsocket clientSocket = nullptr;

//go into command prompt and type 'ipconfig' to see your address
//host and port number
const std::string ipAddress = "localHost";

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
}

bool Connection::OpenSocket()
{
    if (SDLNet_ResolveHost(&m_IP, ipAddress.c_str(), port) == -1)
    {
        std::cout << "Could establish connection to server" << std::endl;
        system("pause");
        return 0;
    }

    m_socket = SDLNet_TCP_Open(&m_IP);

    if (!m_socket)
    {
        std::cout << "Could not connect" << std::endl;
        system("pause");
        return 0;
    }

    std::cout << "Connected to server" << std::endl;
}

void Connection::ListenSocket()
{
}

bool Connection::Send(const std::string& message)
{
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