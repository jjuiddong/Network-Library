#pragma once

//#include "chatBin_Protocol.h"
//#include "chatBin_ProtocolData.h"
//#include "chatBin_ProtocolHandler.h"
//
//#include "chatAsc_Protocol.h"
//#include "chatAsc_ProtocolData.h"
//#include "chatAsc_ProtocolHandler.h"

#include "../Protocol/Src/chatBin_Protocol.h"
#include "../Protocol/Src/chatBin_ProtocolData.h"
#include "../Protocol/Src/chatBin_ProtocolHandler.h"

#include "../Protocol/Src/chatAsc_Protocol.h"
#include "../Protocol/Src/chatAsc_ProtocolData.h"
#include "../Protocol/Src/chatAsc_ProtocolHandler.h"

// 서버 class
class cChatingServer : 
	public chatBin::c2s_ProtocolHandler ,
	public chatAsc::asc_ProtocolHandler
{
public:
	cChatingServer();
	~cChatingServer();

public:
	virtual bool ReqLogin(chatBin::ReqLogin_Packet &packet) override;
	virtual bool ReqLogout(chatBin::ReqLogout_Packet &packet) override;
	virtual bool chat(chatBin::chat_Packet &packet) override;
	virtual bool chatStruct(chatBin::chatStruct_Packet &packet) override;

	virtual bool ReqLogin(chatAsc::ReqLogin_Packet &packet) override;
	virtual bool ReqLogout(chatAsc::ReqLogout_Packet &packet) override;
	virtual bool chat(chatAsc::chat_Packet &packet) override;
	virtual bool chatstruct(chatAsc::chatstruct_Packet &packet) override;

public:
	network2::cTcpServer m_server;
	chatBin::s2c_Protocol m_prtBin;
	chatAsc::asc_Protocol m_prtAsc;
};

// 클라이언트 class
class cChatingClient : 
	public chatBin::s2c_ProtocolHandler ,
	public chatAsc::asc_ProtocolHandler
{
public:
	cChatingClient();
	~cChatingClient();

public:
	virtual bool AckLogin(chatBin::AckLogin_Packet &packet) override;
	virtual bool notice(chatBin::notice_Packet &packet) override;
	virtual bool broadcasting(chatBin::broadcasting_Packet &packet) override;
	virtual bool broadcastingStruct(chatBin::broadcastingStruct_Packet &packet) override;

	virtual bool AckLogin(chatAsc::AckLogin_Packet &packet) override;
	virtual bool notice(chatAsc::notice_Packet &packet) override;
	virtual bool broadcasting(chatAsc::broadcasting_Packet &packet) override;
	virtual bool broadcastingStruct(chatAsc::broadcastingStruct_Packet &packet) override;
	void Process();

public:
	network2::cTcpClient m_client;
	chatBin::c2s_Protocol m_prtBin;
	chatAsc::asc_Protocol prtAsc;

	char m_name[32];
};