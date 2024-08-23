#pragma once
#include "../dependencies/common.h"
#pragma comment(lib, "ws2_32.lib")

class PortManager
{
public:
	void ScanPort(const std::string& host, int port);
	void OutputScannedPorts();
	void OutputOpenPorts();

private:
	std::vector<int> scannedPorts;
	std::vector<int> openPorts;

	WSADATA wsaData;
	SOCKET sock = INVALID_SOCKET;
	sockaddr_in server;
};