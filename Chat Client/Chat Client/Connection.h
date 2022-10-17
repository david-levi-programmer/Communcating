#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

#pragma once

class Connection
{

public:

	bool Initaialize();
	bool OpenSocket();
	void ListenSocket() {}

	bool Send(const std::string& message);
	bool Receive(std::string& message);

	void CloseSocket();
	void ShutDown();

private:

	IPaddress m_IP;
	TCPsocket m_socket = nullptr;

};