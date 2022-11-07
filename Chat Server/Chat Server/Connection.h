#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

#pragma once

constexpr int MAX_CLIENTS = 4;

class Connection
{

public:

	bool Initaialize();
	bool OpenSocket();
	bool ListenSocket();

	bool Send(/*std::string& messageSent*/);
	bool Receive(std::string& message);

	void CloseSocket();
	void ShutDown();

private:

	IPaddress m_IP;
	TCPsocket m_listenSocket = nullptr;
	TCPsocket m_clientSocket = nullptr;
	int m_totalClients;

	//std::string& messageSent;
	//std::string& messageReceived;

};