#ifndef _TCPSENDER_H
#define _TCPSENDER_H

#include "Sender.h"

class TcpSender
	: public Sender
{
public:
	TcpSender();

	virtual bool Start(const std::string &IP, const std::string &Port);

	virtual bool SendFile(std::ifstream *const File, const std::string &Target) const;

	unsigned int ReadSize;

protected:
	bool Send(const std::string &Message) const;
	bool SendPlain(const std::string &Message) const;
};

#endif