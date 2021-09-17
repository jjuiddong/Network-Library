//------------------------------------------------------------------------
// Name:    basic_ProtocolHandler.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

#include "basic_ProtocolData.h"

namespace basic {

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
	static cPacketHeader s_packetHeader;
};
static s2c_Dispatcher g_basic_s2c_Dispatcher;


// ProtocolHandler
class s2c_ProtocolHandler : virtual public network2::iProtocolHandler
{
public:
	friend class s2c_Dispatcher;
	s2c_ProtocolHandler() { m_format = ePacketFormat::BINARY; }
	virtual bool AckLogin(basic::AckLogin_Packet &packet) { return true; }
	virtual bool ReqWork(basic::ReqWork_Packet &packet) { return true; }
	virtual bool func1(basic::func1_Packet &packet) { return true; }
	virtual bool func2(basic::func2_Packet &packet) { return true; }
	virtual bool func3(basic::func3_Packet &packet) { return true; }
	virtual bool func4(basic::func4_Packet &packet) { return true; }
};


static const int c2s_Dispatcher_ID = 300;

// Protocol Dispatcher
class c2s_Dispatcher: public network2::cProtocolDispatcher
{
public:
	c2s_Dispatcher();
protected:
	virtual bool Dispatch(cPacket &packet, const ProtocolHandlers &handlers) override;
	static cPacketHeader s_packetHeader;
};
static c2s_Dispatcher g_basic_c2s_Dispatcher;


// ProtocolHandler
class c2s_ProtocolHandler : virtual public network2::iProtocolHandler
{
public:
	friend class c2s_Dispatcher;
	c2s_ProtocolHandler() { m_format = ePacketFormat::BINARY; }
	virtual bool ReqLogin(basic::ReqLogin_Packet &packet) { return true; }
	virtual bool AckWork(basic::AckWork_Packet &packet) { return true; }
	virtual bool Work(basic::Work_Packet &packet) { return true; }
	virtual bool func5(basic::func5_Packet &packet) { return true; }
	virtual bool func6(basic::func6_Packet &packet) { return true; }
};


}
