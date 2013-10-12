#include "Sender.h"

Sender::~Sender()
{
	if(TargetInfo!=NULL)
	{
		delete TargetInfo;
		TargetInfo=NULL;
	}
}

bool Sender::Start(const std::string &Target, const std::string &Port, const int &SocketType)
{
	WSAData Data;

	if(WSAStartup(MAKEWORD(1, 1), &Data)!=0)
	{
		return false;
	}

	addrinfo *ServerInfo, Hints;

	memset(&Hints, 0, sizeof(Hints));
	Hints.ai_family=AF_UNSPEC;
	Hints.ai_socktype=SocketType;

	int Rcv;
	if((Rcv=getaddrinfo(Target.c_str(), Port.c_str(), &Hints, &ServerInfo))!=0)
	{
		return false;
	}

	addrinfo *p=NULL;
	while(true)
	{
		for(p=ServerInfo; p!=NULL; p=ServerInfo->ai_next)
		{
			if((TargetSocket=socket(p->ai_family, p->ai_socktype, p->ai_protocol))==-1)
			{
				continue;
			}

			if(connect(TargetSocket, p->ai_addr, p->ai_addrlen)==-1)
			{
				continue;
			}

			break;
		}
		if(p!=NULL)
		{
			break;
		}
	}

	char s[INET6_ADDRSTRLEN];
	inet_ntop(p->ai_family, p->ai_addr, s, sizeof(s));
	TargetIP=std::string(s);
	TargetInfo=p;
	freeaddrinfo(ServerInfo);
	return true;
}

bool Sender::SendFile(const std::string& Path, const std::string& Target) const
{
	// Delegate to overloaded function
	std::ifstream *Input=new std::ifstream(Path, std::ios_base::in | std::ios_base::binary | std::ios_base::beg);
	if(!Input->good())
	{
		Input->close();
		delete Input;
		return false;
	}

	bool Succeeded=SendFile(Input, Target);
	Input->close();
	delete Input;

	return Succeeded;
}

std::string Sender::GetTargetIP() const
{
	return TargetIP;
}
SOCKET Sender::GetSocket() const
{
	return TargetSocket;
}