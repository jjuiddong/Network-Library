//------------------------------------------------------------------------
// Name:    chatBin_ProtocolHandler.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

#include "chatBin_ProtocolData.h"

namespace chatBin {

using namespace network2;
using namespace marshalling;
static const int s2c_Dispatcher_ID = 200;

// Protocol Dispatcher
class s2c_Dispatcher: public network2::cProtocolDispatcher
{
public:
	s2c_Dispatcher();
protected:
	virtual bool Dispatch(cPacket &packet, const ProtocolHandlers &handlers) override;
};
static s2c_Dispatcher g_chatBin_s2c_Dispatcher;


// ProtocolHandler
class s2c_ProtocolHandler : virtual public network2::iProtocolHandler
{
	friend class s2c_Dispatcher;
	virtual bool AckLogin(chatBin::AckLogin_Packet &packet) { return true; }
	virtual bool notice(chatBin::notice_Packet &packet) { return true; }
	virtual bool broadcasting(chatBin::broadcasting_Packet &packet) { return true; }
	virtual bool broadcastingStruct(chatBin::broadcastingStruct_Packet &packet) { return true; }
};


static const int c2s_Dispatcher_ID = 300;

// Protocol Dispatcher
class c2s_Dispatcher: public network2::cProtocolDispatcher
{
public:
	c2s_Dispatcher();
protected:
	virtual bool Dispatch(cPacket &packet, const ProtocolHandlers &handlers) override;
};
static c2s_Dispatcher g_chatBin_c2s_Dispatcher;


// ProtocolHandler
class c2s_ProtocolHandler : virtual public network2::iProtocolHandler
{
	friend class c2s_Dispatcher;
	virtual bool ReqLogin(chatBin::ReqLogin_Packet &packet) { return true; }
	virtual bool ReqLogout(chatBin::ReqLogout_Packet &packet) { return true; }
	virtual bool chat(chatBin::chat_Packet &packet) { return true; }
	virtual bool chatStruct(chatBin::chatStruct_Packet &packet) { return true; }
};


}
