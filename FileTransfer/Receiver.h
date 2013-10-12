#ifndef _RECEIVER_H
#define _RECEIVER_H

#include <string>
#include <fstream>

#include <WS2tcpip.h>
#include <winsock.h>
#include <Windows.h>

class Receiver
{
public:
	virtual bool ReceiveFile(const std::string &Path, const std::string &Target)=0;
	virtual bool ReceiveFile(std::ofstream *const File, const std::string &Target)=0;

	virtual std::string GetTargetIP();
	virtual SOCKET GetSocket();

protected:
	std::string TargetIP;
	SOCKET TargetSocket;
};

#endif