#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include "chating.h"

using namespace std;
using namespace network2;

cChatingServer::cChatingServer() :
	m_server(new cPacketHeaderAscii(), new cSessionFactory())
{
	m_server.AddProtocolHandler(this);
	m_server.RegisterProtocol(&m_prtAsc);
}

cChatingServer::~cChatingServer()
{

}

bool cChatingServer::ReqLogin(chatBin::ReqLogin_Packet & packet)
{
	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	session->m_name = packet.id;
	cout << session->m_name.m_str << " Login.\n";
	m_prtBin.AckLogin(packet.senderId);
	return true;
}

bool cChatingServer::ReqLogout(chatBin::ReqLogout_Packet & packet)
{
	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	cout << packet.id << " Logout.\n";
	m_server.RemoveSession(packet.senderId);
	m_prtBin.notice(network2::ALL_NETID, session->m_name.m_str);
	return true;
}

bool cChatingServer::chat(chatBin::chat_Packet & packet)
{
	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	cout << "ID = " << session->m_name.m_str << "\t";
	cout << "Data = " << packet.data << "\n";
	m_prtBin.broadcasting(network2::ALL_NETID, session->m_name.m_str, packet.data);
	return true;
}

bool cChatingServer::chatStruct(chatBin::chatStruct_Packet & packet)
{
	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	cout << "ID = " << session->m_name.m_str << "\t";
	cout << "Data = " << packet.chat.data << "\n";
	m_prtBin.broadcastingStruct(network2::ALL_NETID, session->m_name.m_str, packet.chat);
	return true;
}

bool cChatingServer::ReqLogin(chatAsc::ReqLogin_Packet &packet)
{
	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	session->m_name = packet.name;
	cout << session->m_name.m_str << " Login.\n";
	m_prtAsc.AckLogin(packet.senderId);
	return true;
}

bool cChatingServer::ReqLogout(chatAsc::ReqLogout_Packet & packet)
{
	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	cout << packet.name << " Logout.\n";
	m_prtAsc.notice(network2::ALL_NETID, session->m_name.m_str);
	m_server.RemoveSession(packet.senderId);
	return true;
}

bool cChatingServer::chat(chatAsc::chat_Packet & packet)
{
	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	cout << "ID = " << session->m_name.m_str << "\t";
	cout << "Data = " << packet.data << endl;
	m_prtAsc.broadcasting(network2::ALL_NETID, session->m_name.m_str, packet.data);

	return true;
}

bool cChatingServer::chatstruct(chatAsc::chatstruct_Packet &packet)
{
	const int packetId = packet.pdispatcher->m_packet->GetPacketId();
	BYTE ID[5]{ NULL };
	*(int*)ID = packetId;
	string idstr;
	idstr.resize(5);
	memmove_s(&idstr, 5, ID, 5);

	network2::cSession *session = m_server.FindSessionByNetId(packet.senderId);
	cout << "ID = " << session->m_name.m_str << "\t";
	cout << "Data = " << idstr << " " << packet.sChat.data << endl;
	m_prtAsc.broadcastingStruct(network2::ALL_NETID, session->m_name.m_str, packet.sChat);

	return true;
}

cChatingClient::cChatingClient() :
	m_client(new network2::cPacketHeaderAscii())
{
	m_client.AddProtocolHandler(this);
	m_client.RegisterProtocol(&prtAsc);
}

cChatingClient::~cChatingClient()
{
}

bool cChatingClient::AckLogin(chatBin::AckLogin_Packet & packet)
{
	cout << "You are joined.\n";
	return true;
}

bool cChatingClient::notice(chatBin::notice_Packet & packet)
{
	if (packet.name != m_name)
		cout << packet.name << " out." << endl;
	return true;
}

bool cChatingClient::broadcasting(chatBin::broadcasting_Packet & packet)
{
	if (packet.name != m_name)
		cout << packet.name << " : " << packet.data << endl;
	return true;
}

bool cChatingClient::broadcastingStruct(chatBin::broadcastingStruct_Packet & packet)
{
	if (packet.name != m_name)
		cout << packet.name << " : " << packet.chat.data << endl;
	return true;
}

bool cChatingClient::AckLogin(chatAsc::AckLogin_Packet & packet)
{
	cout << "You are joined.\n";
	return true;
}

bool cChatingClient::notice(chatAsc::notice_Packet &packet)
{
	if (packet.name != m_name)
		cout << packet.name << " : " << packet.name << endl;
	return true;
}

bool cChatingClient::broadcasting(chatAsc::broadcasting_Packet &packet)
{
	if (packet.name != m_name)
		cout << packet.name << " : " << packet.data << endl;
	return true;
}

bool cChatingClient::broadcastingStruct(chatAsc::broadcastingStruct_Packet &packet)
{
	const int packetId = packet.pdispatcher->m_packet->GetPacketId();
	BYTE ID[5]{ NULL };
	*(int*)ID = packetId;
	string idstr;
	idstr.resize(5);
	memmove_s(&idstr, 5, ID, 5);

	if (packet.name != m_name) 
	{
		cout << packet.name << " : ";
		cout << idstr << " " << packet.sChat.data << endl;
	}
	return true;
}

void cChatingClient::Process()
{
	if (_kbhit())
	{
		char c = _getch();

		if (c == '\r')
		{
			cout << "Comment : ";
			char data[64] = { 0 };
			scanf("%s", data);
			string chat_str(data);

			const bool isBinaryProtocol = m_client.GetPacketHeader()->GetHeaderSize() > 10;
			if (isBinaryProtocol)
			{
				if (chat_str == "Login") 
				{
					cout << "ID : ";
					scanf("%s", m_name);
					m_prtBin.ReqLogin(network2::SERVER_NETID, m_name);
				}
				else if (chat_str == "Logout")
				{
					m_prtBin.ReqLogout(network2::SERVER_NETID, m_name);
				}
				else 
				{
					m_prtBin.chat(network2::SERVER_NETID, chat_str);
					network2::sChatStruct chatTest = network2::sChatStruct(m_name, chat_str, m_client.GetId());
					m_prtBin.chatStruct(network2::SERVER_NETID, chatTest);
				}
			}
			else
			{
				if (chat_str == "Login") 
				{
					cout << "ID : ";
					scanf("%s", m_name);
					prtAsc.ReqLogin(network2::SERVER_NETID, m_name);
				}
				else if (chat_str == "Logout")
				{
					prtAsc.ReqLogout(network2::SERVER_NETID, m_name);
				}
				else 
				{
					prtAsc.chat(network2::SERVER_NETID, chat_str);
					network2::sChatStruct chatTest = network2::sChatStruct(m_name, chat_str, m_client.GetId());
					prtAsc.chatstruct(network2::SERVER_NETID, chatTest);
				}
			}
		}
	}
}
