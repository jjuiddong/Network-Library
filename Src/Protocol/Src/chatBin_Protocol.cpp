#include "pch.h"
#include "chatBin_Protocol.h"
using namespace chatBin;

//------------------------------------------------------------------------
// Protocol: AckLogin
//------------------------------------------------------------------------
void chatBin::s2c_Protocol::AckLogin(netid targetId)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 851424104 );
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: notice
//------------------------------------------------------------------------
void chatBin::s2c_Protocol::notice(netid targetId, const std::string &name)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 27040168 );
	packet << name;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: broadcasting
//------------------------------------------------------------------------
void chatBin::s2c_Protocol::broadcasting(netid targetId, const std::string &name, const std::string &data)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3651228816 );
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
void chatBin::s2c_Protocol::broadcastingStruct(netid targetId, const std::string &name, const sChatStruct &chat)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 810651236 );
	packet << name;
	AddDelimeter(packet);
	packet << chat;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



//------------------------------------------------------------------------
// Protocol: ReqLogin
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::ReqLogin(netid targetId, const string &id)
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
// Protocol: ReqLogout
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::ReqLogout(netid targetId, const string &id)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1095604361 );
	packet << id;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: chat
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::chat(netid targetId, const std::string &data)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3009973762 );
	packet << data;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: chatStruct
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::chatStruct(netid targetId, const sChatStruct &chat)
{
	cPacket packet(m_node->GetPacketHeader());
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 350845456 );
	packet << chat;
	AddDelimeter(packet);
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



