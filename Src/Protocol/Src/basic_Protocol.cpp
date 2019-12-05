#include "pch.h"
#include "basic_Protocol.h"
using namespace basic;

//------------------------------------------------------------------------
// Protocol: AckLogin
//------------------------------------------------------------------------
void basic::s2c_Protocol::AckLogin(netid targetId, const string &id)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 851424104 );
	packet << id;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: ReqWork
//------------------------------------------------------------------------
void basic::s2c_Protocol::ReqWork(netid targetId, const int &num)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3933130150 );
	packet << num;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func1
//------------------------------------------------------------------------
void basic::s2c_Protocol::func1(netid targetId)
{
	cPacket packet(m_node->GetPacketHeader());
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
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 2592878926 );
	packet << str;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func3
//------------------------------------------------------------------------
void basic::s2c_Protocol::func3(netid targetId, const float &value)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3387225200 );
	packet << value;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func4
//------------------------------------------------------------------------
void basic::s2c_Protocol::func4(netid targetId)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 4124054319 );
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



//------------------------------------------------------------------------
// Protocol: ReqLogin
//------------------------------------------------------------------------
void basic::c2s_Protocol::ReqLogin(netid targetId, const string &id)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1956887904 );
	packet << id;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: AckWork
//------------------------------------------------------------------------
void basic::c2s_Protocol::AckWork(netid targetId, const int &result)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3785607084 );
	packet << result;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: Work
//------------------------------------------------------------------------
void basic::c2s_Protocol::Work(netid targetId, const int &workId, const int &status, const int &statusValue, const vector<int> &path, const string &name)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 964611405 );
	packet << workId;
	AddDelimeter(packet);
	packet << status;
	AddDelimeter(packet);
	packet << statusValue;
	AddDelimeter(packet);
	packet << path;
	AddDelimeter(packet);
	packet << name;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func5
//------------------------------------------------------------------------
void basic::c2s_Protocol::func5(netid targetId, const std::string &str)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 622789402 );
	packet << str;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: func6
//------------------------------------------------------------------------
void basic::c2s_Protocol::func6(netid targetId, const float &value)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1506470321 );
	packet << value;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



