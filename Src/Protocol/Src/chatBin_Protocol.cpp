#include "pch.h"
#include "chatBin_Protocol.h"
using namespace chatBin;

cPacketHeader chatBin::s2c_Protocol::s_packetHeader;
//------------------------------------------------------------------------
// Protocol: AckLogin
//------------------------------------------------------------------------
void chatBin::s2c_Protocol::AckLogin(netid targetId)
{
	cPacket packet(&s_packetHeader);
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
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 27040168 );
	packet << name;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: broadcasting
//------------------------------------------------------------------------
void chatBin::s2c_Protocol::broadcasting(netid targetId, const std::string &name, const std::string &data)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3651228816 );
	packet << name;
	packet << data;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: broadcastingStruct
//------------------------------------------------------------------------
void chatBin::s2c_Protocol::broadcastingStruct(netid targetId, const std::string &name, const sChatStruct &chat)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 810651236 );
	packet << name;
	packet << chat;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



cPacketHeader chatBin::c2s_Protocol::s_packetHeader;
//------------------------------------------------------------------------
// Protocol: ReqLogin
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::ReqLogin(netid targetId, const string &id)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1956887904 );
	packet << id;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: ReqLogout
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::ReqLogout(netid targetId, const string &id)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 1095604361 );
	packet << id;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: chat
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::chat(netid targetId, const std::string &data)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 3009973762 );
	packet << data;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}

//------------------------------------------------------------------------
// Protocol: chatStruct
//------------------------------------------------------------------------
void chatBin::c2s_Protocol::chatStruct(netid targetId, const sChatStruct &chat)
{
	cPacket packet(&s_packetHeader);
	packet.SetProtocolId( GetId() );
	packet.SetPacketId( 350845456 );
	packet << chat;
	packet.EndPack();
	GetNode()->Send(targetId, packet);
}



