#pragma once

namespace network2
{
	struct sChatStruct {
		sChatStruct() : name(""), data(""), id() {};
		sChatStruct(string _name, string _data, int _id) : name(_name), data(_data), id(_id) {};

		string name;
		string data;
		int id;
	};

	namespace marshalling
	{
		cPacket& operator<<(cPacket &packet, const sChatStruct &chat);
		cPacket& operator>>(cPacket &packet, OUT sChatStruct &chat);
	}

	namespace marshalling_ascii
	{
		cPacket& operator<<(cPacket &packet, const sChatStruct &chat);
		cPacket& operator>>(cPacket &packet, OUT sChatStruct &chat);
	}
}

