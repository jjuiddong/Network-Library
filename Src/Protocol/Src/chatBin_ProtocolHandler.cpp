#include "pch.h"
#include "chatBin_ProtocolHandler.h"

using namespace chatBin;


cPacketHeader chatBin::s2c_Dispatcher::s_packetHeader;
chatBin::s2c_Dispatcher::s2c_Dispatcher()
	: cProtocolDispatcher(chatBin::s2c_Dispatcher_ID, ePacketFormat::BINARY)
{
	cProtocolDispatcher::GetDispatcherMap()->insert({s2c_Dispatcher_ID, this});
	cProtocolDispatcher::GetPacketHeaderMap()->insert({s2c_Dispatcher_ID, &s_packetHeader});
}

//------------------------------------------------------------------------
// 패킷의 프로토콜에 따라 해당하는 핸들러를 호출한다.
//------------------------------------------------------------------------
bool chatBin::s2c_Dispatcher::Dispatch(cPacket &packet, const ProtocolHandlers &handlers)
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
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, AckLogin(data));
		}
		break;

	case 27040168: // notice
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			notice_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, notice(data));
		}
		break;

	case 3651228816: // broadcasting
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			broadcasting_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			packet >> data.data;
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, broadcasting(data));
		}
		break;

	case 810651236: // broadcastingStruct
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<s2c_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			broadcastingStruct_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.name;
			packet >> data.chat;
			SEND_HANDLER(s2c_ProtocolHandler, prtHandler, broadcastingStruct(data));
		}
		break;

	default:
		assert(0);
		break;
	}
	return true;
}




cPacketHeader chatBin::c2s_Dispatcher::s_packetHeader;
chatBin::c2s_Dispatcher::c2s_Dispatcher()
	: cProtocolDispatcher(chatBin::c2s_Dispatcher_ID, ePacketFormat::BINARY)
{
	cProtocolDispatcher::GetDispatcherMap()->insert({c2s_Dispatcher_ID, this});
	cProtocolDispatcher::GetPacketHeaderMap()->insert({c2s_Dispatcher_ID, &s_packetHeader});
}

//------------------------------------------------------------------------
// 패킷의 프로토콜에 따라 해당하는 핸들러를 호출한다.
//------------------------------------------------------------------------
bool chatBin::c2s_Dispatcher::Dispatch(cPacket &packet, const ProtocolHandlers &handlers)
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

	case 1095604361: // ReqLogout
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			ReqLogout_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.id;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, ReqLogout(data));
		}
		break;

	case 3009973762: // chat
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			chat_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.data;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, chat(data));
		}
		break;

	case 350845456: // chatStruct
		{
			ProtocolHandlers prtHandler;
			if (!HandlerMatching<c2s_ProtocolHandler>(handlers, prtHandler))
				return false;

			SetCurrentDispatchPacket( &packet );

			chatStruct_Packet data;
			data.pdispatcher = this;
			data.senderId = packet.GetSenderId();
			packet >> data.chat;
			SEND_HANDLER(c2s_ProtocolHandler, prtHandler, chatStruct(data));
		}
		break;

	default:
		assert(0);
		break;
	}
	return true;
}



