#include "pch.h"
#include "chatAsc_Protocol.h"
using namespace chatAsc;

//------------------------------------------------------------------------
// Protocol: AckLogin
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::AckLogin(netid targetId)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 851424104 );
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: ReqLogin
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::ReqLogin(netid targetId, const string &name)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1956887904 );
	packet << name;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: ReqLogout
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::ReqLogout(netid targetId, const string &name)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1095604361 );
	packet << name;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: chat
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::chat(netid targetId, const std::string &data)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1145980243 );
	packet << data;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: chatstruct
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::chatstruct(netid targetId, const sChatStruct &sChat)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1413564483 );
	packet << sChat;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: notice
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::notice(netid targetId, const std::string &name)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1313821763 );
	packet << name;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: broadcasting
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::broadcasting(netid targetId, const std::string &name, const std::string &data)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1128550978 );
	packet << name;
	AddDelimeter(packet);
	packet << data;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: broadcastingStruct
//------------------------------------------------------------------------
void chatAsc::asc_Protocol::broadcastingStruct(netid targetId, const std::string &name, const sChatStruct &sChat)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1396986434 );
	packet << name;
	AddDelimeter(packet);
	packet << sChat;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



