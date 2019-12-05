//------------------------------------------------------------------------
// Name:    chatBin_Protocol.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

namespace chatBin {

using namespace network2;
using namespace marshalling;
static const int s2c_Protocol_ID = 200;

class s2c_Protocol : public network2::iProtocol
{
public:
	s2c_Protocol() : iProtocol(s2c_Protocol_ID) {}
	void AckLogin(netid targetId);
	void notice(netid targetId, const std::string &name);
	void broadcasting(netid targetId, const std::string &name, const std::string &data);
	void broadcastingStruct(netid targetId, const std::string &name, const sChatStruct &chat);
};
static const int c2s_Protocol_ID = 300;

class c2s_Protocol : public network2::iProtocol
{
public:
	c2s_Protocol() : iProtocol(c2s_Protocol_ID) {}
	void ReqLogin(netid targetId, const string &id);
	void ReqLogout(netid targetId, const string &id);
	void chat(netid targetId, const std::string &data);
	void chatStruct(netid targetId, const sChatStruct &chat);
};
}
