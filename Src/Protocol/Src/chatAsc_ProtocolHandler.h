//------------------------------------------------------------------------
// Name:    chatAsc_ProtocolHandler.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

#include "chatAsc_ProtocolData.h"

namespace chatAsc {

using namespace network2;
using namespace marshalling_ascii;
static const int asc_Dispatcher_ID = 100;

// Protocol Dispatcher
class asc_Dispatcher: public network2::cProtocolDispatcher
{
public:
	asc_Dispatcher();
protected:
	virtual bool Dispatch(cPacket &packet, const ProtocolHandlers &handlers) override;
};
static asc_Dispatcher g_chatAsc_asc_Dispatcher;


// ProtocolHandler
class asc_ProtocolHandler : virtual public network2::iProtocolHandler
{
public:
	friend class asc_Dispatcher;
	asc_ProtocolHandler() { m_format = ePacketFormat::ASCII; }
	virtual bool AckLogin(chatAsc::AckLogin_Packet &packet) { return true; }
	virtual bool ReqLogin(chatAsc::ReqLogin_Packet &packet) { return true; }
	virtual bool ReqLogout(chatAsc::ReqLogout_Packet &packet) { return true; }
	virtual bool chat(chatAsc::chat_Packet &packet) { return true; }
	virtual bool chatstruct(chatAsc::chatstruct_Packet &packet) { return true; }
	virtual bool notice(chatAsc::notice_Packet &packet) { return true; }
	virtual bool broadcasting(chatAsc::broadcasting_Packet &packet) { return true; }
	virtual bool broadcastingStruct(chatAsc::broadcastingStruct_Packet &packet) { return true; }
};


}
