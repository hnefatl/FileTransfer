#ifndef _UDPSENDER_H
#define _UDPSENDER_H

#include "Sender.h"

#include "Packet.h"

class UdpSender
	: public Sender
{
public:
	virtual bool Start(const std::string &IP, const std::string &Port);

	virtual bool SendFile(const std::string &Path, const std::string &Target) const;
	virtual bool SendFile(std::ifstream *const File, const std::string &Target) const;

protected:
	virtual bool SendPacket(const Packet &P) const;
};

#endif