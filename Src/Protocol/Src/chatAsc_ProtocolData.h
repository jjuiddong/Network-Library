//------------------------------------------------------------------------
// Name:    chatAsc_ProtocolData.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

namespace chatAsc {

using namespace network2;
using namespace marshalling_ascii;


	struct AckLogin_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
	};

	struct ReqLogin_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		string name;
	};

	struct ReqLogout_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		string name;
	};

	struct chat_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		std::string data;
	};

	struct chatstruct_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		sChatStruct sChat;
	};

	struct notice_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		std::string name;
	};

	struct broadcasting_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		std::string name;
		std::string data;
	};

	struct broadcastingStruct_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		std::string name;
		sChatStruct sChat;
	};



}
