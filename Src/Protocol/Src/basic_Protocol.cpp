#include "pch.h"
#include "basic_Protocol.h"
using namespace basic;

cPacketHeader basic::s2c_Protocol::s_packetHeader;
//------------------------------------------------------------------------
// Protocol: AckLogin
//------------------------------------------------------------------------
void basic::s2c_Protocol::AckLogin(netid targetId, const string &id)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 851424104 );
	packet << id;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: ReqWork
//------------------------------------------------------------------------
void basic::s2c_Protocol::ReqWork(netid targetId, const int &num)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3933130150 );
	packet << num;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func1
//------------------------------------------------------------------------
void basic::s2c_Protocol::func1(netid targetId)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3587614684 );
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func2
//------------------------------------------------------------------------
void basic::s2c_Protocol::func2(netid targetId, const std::string &str)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 2592878926 );
	packet << str;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func3
//------------------------------------------------------------------------
void basic::s2c_Protocol::func3(netid targetId, const float &value)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3387225200 );
	packet << value;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func4
//------------------------------------------------------------------------
void basic::s2c_Protocol::func4(netid targetId)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 4124054319 );
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



cPacketHeader basic::c2s_Protocol::s_packetHeader;
//------------------------------------------------------------------------
// Protocol: ReqLogin
//------------------------------------------------------------------------
void basic::c2s_Protocol::ReqLogin(netid targetId, const string &id)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1956887904 );
	packet << id;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: AckWork
//------------------------------------------------------------------------
void basic::c2s_Protocol::AckWork(netid targetId, const int &result)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3785607084 );
	packet << result;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: Work
//------------------------------------------------------------------------
void basic::c2s_Protocol::Work(netid targetId, const int &workId, const int &status, const int &statusValue, const vector<int> &path, const string &name)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 964611405 );
	packet << workId;
	packet << status;
	packet << statusValue;
	packet << path;
	packet << name;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func5
//------------------------------------------------------------------------
void basic::c2s_Protocol::func5(netid targetId, const std::string &str)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 622789402 );
	packet << str;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func6
//------------------------------------------------------------------------
void basic::c2s_Protocol::func6(netid targetId, const float &value)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1506470321 );
	packet << value;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



