#include "portmanager.h"

void PortManager::ScanPort(const std::string& host, int port)
{
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		std::cerr << "WSAStartup failed\n";
		return;
	}

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		std::cerr << "Failed to create socket\n";
		WSACleanup();
		return;
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	inet_pton(AF_INET, host.c_str(), &server.sin_addr);

	int result = connect(sock, (struct sockaddr*)&server, sizeof(server));
	if (result == SOCKET_ERROR)
	{
		scannedPorts.push_back(port);
		std::cout << "Port: " << port << " is closed on: " << host << std::endl;
	}
	else
	{
		openPorts.push_back(port);
		std::cout << "Port: " << port << " is open on: " << host << std::endl;
	}

	closesocket(sock);
	WSACleanup();
}

void PortManager::OutputScannedPorts()
{
	for (const auto& port : scannedPorts)
	{
		std::printf("closed Port: %d\n", port);
	}
}

void PortManager::OutputOpenPorts()
{
	for (const auto& port : openPorts)
	{
		std::printf("open Port: %d\n", port);
	}
}
