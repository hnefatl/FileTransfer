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
	virtual bool SendFile(const std::string &Path, const std::string &Target)=0;
	virtual bool SendFile(std::ifstream *const File, const std::string &Target)=0;

	virtual bool ReceiveFile(const std::string &Path, const std::string &Target)=0;
	virtual bool ReceiveFile(std::ofstream *const File, const std::string &Target)=0;
};

#endif