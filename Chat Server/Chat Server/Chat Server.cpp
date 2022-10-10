#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

//go into command prompt and type 'ipconfig' to see your address
//host and port number
IPaddress ip;

const int port = 1234;

int main(int argc, char* argv[])
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

    //===========server-specific==========================
    TCPsocket listenSocket = nullptr;
    TCPsocket clientSocket = nullptr;

    //setup with specific port number
    //as host, we use nullptr
    if (SDLNet_ResolveHost(&ip, nullptr, port) == -1)
    {
        std::cout << "Could not create server" << std::endl;
        system("pause");
        return 0;
    }

    //if server created above, open listen socket
    listenSocket = SDLNet_TCP_Open(&ip);

    if (!listenSocket)
    {
        std::cout << "Could not open listening socket" << std::endl << std::endl;
        system("pause");
        return 0;
    }

    std::cout << "Sokcet open for clients." << std::endl << std::endl;
    std::cout << "Waiting for client." << std::endl;

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

    //====================================================

    SDLNet_Quit();
    SDL_Quit();

    system("pause");
    return 0;
}