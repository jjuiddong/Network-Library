#include "pch.h"
#include "basic_ProtocolHandler.h"

using namespace basic;


cPacketHeader basic::s2c_Dispatcher::s_packetHeader;
basic::s2c_Dispatcher::s2c_Dispatcher()
	: cProtocolDispatcher(basic::s2c_Dispatcher_ID, ePacketFormat::BINARY)
{
	cProtocolDispatcher::GetDispatcherMap()->insert({s2c_Dispatcher_ID, this});
	cProtocolDispatcher::GetPacketHeaderMap()->insert({s2c_Dispatcher_ID, &s_packetHeader});
}

//------------------------------------------------------------------------
// 패킷의 프로토콜에 따라 해당하는 핸들러를 호출한다.
//------------------------------------------------------------------------
bool basic::s2c_Dispatcher::Dispatch(cPacket &packet, const ProtocolHandlers &handlers)
{
	const int protocolId = packet.GetProtocolId();
	const int packetId = packet.GetPacketId();
	switch (packetId)
	{
	case 851424104: // AckLogin
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			AckLogin_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.id;
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, AckLogin(data));
		}
		break;

	case 3933130150: // ReqWork
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			ReqWork_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.num;
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, ReqWork(data));
		}
		break;

	case 3587614684: // func1
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			func1_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, func1(data));
		}
		break;

	case 2592878926: // func2
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			func2_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.str;
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, func2(data));
		}
		break;

	case 3387225200: // func3
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			func3_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.value;
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, func3(data));
		}
		break;

	case 4124054319: // func4
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			func4_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, func4(data));
		}
		break;

	default:
		assert(0);
		break;
	}
	return true;
}




cPacketHeader basic::c2s_Dispatcher::s_packetHeader;
basic::c2s_Dispatcher::c2s_Dispatcher()
	: cProtocolDispatcher(basic::c2s_Dispatcher_ID, ePacketFormat::BINARY)
{
	cProtocolDispatcher::GetDispatcherMap()->insert({c2s_Dispatcher_ID, this});
	cProtocolDispatcher::GetPacketHeaderMap()->insert({c2s_Dispatcher_ID, &s_packetHeader});
}

//------------------------------------------------------------------------
// 패킷의 프로토콜에 따라 해당하는 핸들러를 호출한다.
//------------------------------------------------------------------------
bool basic::c2s_Dispatcher::Dispatch(cPacket &packet, const ProtocolHandlers &handlers)
{
	const int protocolId = packet.GetProtocolId();
	const int packetId = packet.GetPacketId();
	switch (packetId)
	{
	case 1956887904: // ReqLogin
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			ReqLogin_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.id;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, ReqLogin(data));
		}
		break;

	case 3785607084: // AckWork
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			AckWork_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.result;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, AckWork(data));
		}
		break;

	case 964611405: // Work
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			Work_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.workId;
			packet >> data.status;
			packet >> data.statusValue;
			packet >> data.path;
			packet >> data.name;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, Work(data));
		}
		break;

	case 622789402: // func5
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			func5_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.str;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, func5(data));
		}
		break;

	case 1506470321: // func6
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			func6_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.value;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, func6(data));
		}
		break;

	default:
		assert(0);
		break;
	}
	return true;
}



