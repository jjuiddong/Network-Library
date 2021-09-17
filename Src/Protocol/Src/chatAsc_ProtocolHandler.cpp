#include "pch.h"
#include "chatAsc_ProtocolHandler.h"

using namespace chatAsc;


cPacketHeaderAscii chatAsc::asc_Dispatcher::s_packetHeader;
chatAsc::asc_Dispatcher::asc_Dispatcher()
	: cProtocolDispatcher(chatAsc::asc_Dispatcher_ID, ePacketFormat::ASCII)
{
	cProtocolDispatcher::GetDispatcherMap()->insert({asc_Dispatcher_ID, this});
	cProtocolDispatcher::GetPacketHeaderMap()->insert({asc_Dispatcher_ID, &s_packetHeader});
}

//------------------------------------------------------------------------
// 패킷의 프로토콜에 따라 해당하는 핸들러를 호출한다.
//------------------------------------------------------------------------
bool chatAsc::asc_Dispatcher::Dispatch(cPacket &packet, const ProtocolHandlers &handlers)
{
	const int protocolId = packet.GetProtocolId();
	const int packetId = packet.GetPacketId();
	switch (packetId)
	{
	case 851424104: // AckLogin
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			AckLogin_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, AckLogin(data));
		}
		break;

	case 1956887904: // ReqLogin
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			ReqLogin_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, ReqLogin(data));
		}
		break;

	case 1095604361: // ReqLogout
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			ReqLogout_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, ReqLogout(data));
		}
		break;

	case 1145980243: // chat
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			chat_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.data;
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, chat(data));
		}
		break;

	case 1413564483: // chatstruct
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			chatstruct_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.sChat;
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, chatstruct(data));
		}
		break;

	case 1313821763: // notice
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			notice_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, notice(data));
		}
		break;

	case 1128550978: // broadcasting
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			broadcasting_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			packet >> data.data;
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, broadcasting(data));
		}
		break;

	case 1396986434: // broadcastingStruct
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<asc_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			broadcastingStruct_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			packet >> data.sChat;
			SEND_HANDLER(asc_ProtocolHandler, prtHandler, broadcastingStruct(data));
		}
		break;

	default:
		assert(0);
		break;
	}
	return true;
}



