#ifndef _PACKET_H
#define _PACKET_H

#include <vector>

class Packet
{
public:
	Packet();
	Packet(const unsigned long &Number);
	Packet(const unsigned long &Number, const std::vector<unsigned char> &Data);

	std::string GetData() const;
	void LoadData(const std::string &Data);

	unsigned long Number;
	std::vector<unsigned char> Data;
};

#endif