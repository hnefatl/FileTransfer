#ifndef _TCPSENDER_H
#define _TCPSENDER_H

#include "Sender.h"

class TcpSender
	: public Sender
{
public:
	virtual bool SendFile(const std::string &Path, const std::string &Target);
	virtual bool SendFile(std::ifstream *const File, const std::string &Target);

	virtual bool ReceiveFile(const std::string &Path, const std::string &Target);
	virtual bool ReceiveFile(std::ofstream *const File, const std::string &Target);
}

#endif