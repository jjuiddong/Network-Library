#include "pch.h"
#include "chatAsc_ProtocolHandler.h"

using namespace chatAsc;


chatAsc::asc_Dispatcher::asc_Dispatcher()
	: cProtocolDispatcher(chatAsc::asc_Dispatcher_ID)
{
	cProtocolDispatcher::GetDispatcherMap()->insert({asc_Dispatcher_ID, this });
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
	case 851424104:
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

	case 1956887904:
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

	case 1095604361:
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

	case 1145980243:
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

	case 1413564483:
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

	case 1313821763:
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

	case 1128550978:
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

	case 1396986434:
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



