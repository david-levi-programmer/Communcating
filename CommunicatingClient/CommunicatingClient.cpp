#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

//go into command prompt and type 'ipconfig' to see your address
//host and port number
IPaddress ip;

TCPsocket listenSocket = nullptr;
TCPsocket clientSocket = nullptr;

const int port = 1234;

int main(int argc, char* argv[]) //Make a client solution and copy all this into it
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL did not initialize properly." << std::endl;
        system("pause");
        return 0;
    }

    else if (SDLNet_Init() == -1);
    {
        std::cout << "Networking sub-system did not initialize properly." << std::endl;
        system("pause");
        return 0;
    }

    //====================================================
    //client-specific
    const std::string ipAddress = "localHost";


    if (SDLNet_ResolveHost(&ip, ipAddress.c_str(), port) == -1);
    {
        std::cout << "Could establish connection to server" << std::endl;
        system("pause");
        return 0;
    }

    //====================================================
    SDLNet_Quit();
    SDL_Quit();

    system("pause");
    return 0;
}