#ifndef _SENDER_H
#define _SENDER_H

#include <string>
#include <fstream>

#include <WS2tcpip.h>
#include <winsock.h>
#include <Windows.h>

class Sender
{
public:
	virtual ~Sender();

	virtual bool Start(const std::string &IP, const std::string &Target, const int &SocketType);

	virtual bool SendFile(const std::string &Path, const std::string &Target) const;
	virtual bool SendFile(std::ifstream *const File, const std::string &Target) const=0;

	virtual std::string GetTargetIP() const;
	virtual SOCKET GetSocket() const;

protected:
	std::string TargetIP;
	SOCKET TargetSocket;
	addrinfo *TargetInfo;
};

#endif