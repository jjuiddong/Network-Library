//------------------------------------------------------------------------
// Name:    chatAsc_Protocol.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

namespace chatAsc {

using namespace network2;
using namespace marshalling_ascii;
static const int asc_Protocol_ID = 100;

class asc_Protocol : public network2::iProtocol
{
public:
	asc_Protocol() : iProtocol(asc_Protocol_ID, ePacketFormat::ASCII) {}
	void AckLogin(netid targetId);
	void ReqLogin(netid targetId, const string &name);
	void ReqLogout(netid targetId, const string &name);
	void chat(netid targetId, const std::string &data);
	void chatstruct(netid targetId, const sChatStruct &sChat);
	void notice(netid targetId, const std::string &name);
	void broadcasting(netid targetId, const std::string &name, const std::string &data);
	void broadcastingStruct(netid targetId, const std::string &name, const sChatStruct &sChat);
};
}
