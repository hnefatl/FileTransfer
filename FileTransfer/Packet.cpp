#include "Packet.h"

Packet::Packet()
{
	this->Number=0;
}
Packet::Packet(const unsigned long &Number)
{
	this->Number=Number;
}
Packet::Packet(const unsigned long &Number, const std::vector<unsigned char> &Data)
{
	this->Number=Number;
	this->Data=Data;
}

std::string Packet::GetData() const
{
	std::string sData;
	// Create room
	sData.resize(sizeof(Number)+Data.size());
	
	// Set number bytes
	for(unsigned int x=0; x<sizeof(Number); x++)
	{
		// Get the individual bytes and store them
		sData[x]=(unsigned char)((Number>>(sizeof(Number)-x)*8) & 0xFF);
	}

	// Set data bytes
	for(unsigned int x=sizeof(Number); x<sData.size(); x++)
	{
		sData[x]=Data[x];
	}

	return sData;
}
void Packet::LoadData(const std::string &sData)
{
	// Get number
	for(unsigned int x=0; x<sizeof(Number); x++)
	{
		Number|=((unsigned long)sData[x]<<(sizeof(Number)-x)*8);
	}

	// Get data
	for(unsigned int x=sizeof(Number); x<sData.size(); x++)
	{
		Data[x]=sData[x];
	}
}