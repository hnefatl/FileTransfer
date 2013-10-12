#include "TcpSender.h"

#include <sstream>

TcpSender::TcpSender()
{
	ReadSize=256;
}

bool TcpSender::Start(const std::string &IP, const std::string &Port)
{
	return TcpSender::Sender::Start(IP, Port, SOCK_STREAM);
}

bool TcpSender::SendFile(std::ifstream *const File, const std::string &Target) const
{
	unsigned int BytesSent=0;
	unsigned int BytesRead;

	while(true)
	{
		std::string Read;
		Read.resize(ReadSize+1);
		BytesRead=File->readsome(&Read[0], ReadSize);
		if(BytesRead==0)
		{
			break;
		}
		Read[BytesRead]='\0';

		if(!Send(Read))
		{
			return false;
		}
	}

	return true;
}

bool TcpSender::Send(const std::string &Message) const
{
	std::string MessageSizeSize;
	std::string MessageSize;

	std::stringstream Converter;
	Converter<<Message;
	Converter>>MessageSize;
	Converter=std::stringstream();
	Converter<<MessageSize;
	Converter>>MessageSizeSize;

	if(!SendPlain(MessageSizeSize))
	{
		return false;
	}
	if(!SendPlain(MessageSize))
	{
		return false;
	}
	if(!SendPlain(Message))
	{
		return false;
	}

	return true;
}
bool TcpSender::SendPlain(const std::string &Message) const
{
	unsigned int BytesSent=0;
	while(BytesSent!=Message.size())
	{
		unsigned int Sent=send(TargetSocket, Message.c_str()+BytesSent, Message.size()-BytesSent, NULL);
		if(Sent<0)
		{
			return false;
		}
		BytesSent+=Sent;
	}

	return true;
}