#include "pch.h"
#include "chatingData.h"

using namespace common;
using namespace network2;
//using namespace marshalling;
//using namespace marshalling_ascii;

cPacket & network2::marshalling::operator<<(cPacket & packet, const sChatStruct & chat)
{
	packet << chat.name;
	packet << chat.data;
	packet << chat.id;

	return packet;
}

cPacket & network2::marshalling::operator>>(cPacket & packet, OUT sChatStruct & chat)
{
	packet >> chat.name;
	packet >> chat.data;
	packet >> chat.id;

	return packet;
}

cPacket & network2::marshalling_ascii::operator<<(cPacket & packet, const sChatStruct & chat)
{
	packet << chat.name;
	packet.AppendDelimeter(DELIMETER);
	packet << chat.data;
	packet.AppendDelimeter(DELIMETER);
	packet << chat.id;
	packet.EndPack();

	return packet;
}

cPacket & network2::marshalling_ascii::operator>>(cPacket & packet, OUT sChatStruct & chat)
{
	packet >> chat.name;
	packet >> chat.data;
	packet >> chat.id;
	packet.EndPack();

	return packet;
}