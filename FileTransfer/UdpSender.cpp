#include "UdpSender.h"

bool UdpSender::Start(const std::string &IP, const std::string &Port)
{
	return UdpSender::Sender::Start(IP, Port, SOCK_DGRAM);
}

bool UdpSender::SendPacket(const Packet &P) const
{
	std::string Data=P.GetData();
	return sendto(TargetSocket, Data.c_str(), Data.size(), NULL, TargetInfo->ai_addr, TargetInfo->ai_addrlen)>=0;
}