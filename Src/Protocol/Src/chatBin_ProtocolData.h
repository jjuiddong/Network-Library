//------------------------------------------------------------------------
// Name:    chatBin_ProtocolData.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

namespace chatBin {

using namespace network2;
using namespace marshalling;


	struct AckLogin_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
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
		sChatStruct chat;
	};





	struct ReqLogin_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		string id;
	};

	struct ReqLogout_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		string id;
	};

	struct chat_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		std::string data;
	};

	struct chatStruct_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		sChatStruct chat;
	};



}
