//------------------------------------------------------------------------
// Name:    basic_ProtocolData.h
// Author:  ProtocolGenerator (by jjuiddong)
// Date:    
//------------------------------------------------------------------------
#pragma once

namespace basic {

using namespace network2;
using namespace marshalling;


	struct AckLogin_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		string id;
	};

	struct ReqWork_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		int num;
	};

	struct func1_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
	};

	struct func2_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		std::string str;
	};

	struct func3_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		float value;
	};

	struct func4_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
	};





	struct ReqLogin_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		string id;
	};

	struct AckWork_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		int result;
	};

	struct Work_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		int workId;
		int status;
		int statusValue;
		vector<int> path;
		string name;
	};

	struct func5_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		std::string str;
	};

	struct func6_Packet {
		cProtocolDispatcher *pdispatcher;
		netid senderId;
		float value;
	};



}
