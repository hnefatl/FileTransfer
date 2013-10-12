#include "Receiver.h"

std::string Receiver::GetTargetIP()
{
	return TargetIP;
}
SOCKET Receiver::GetSocket()
{
	return TargetSocket;
}