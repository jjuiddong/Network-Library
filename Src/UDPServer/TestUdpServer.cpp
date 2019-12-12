//
// 2019-12-12, jjuiddong
// udp/ip server sample
//	udp server is only receive module
//
#include "pch.h"
#include "../Protocol/Src/basic_Protocol.h"
#include "../Protocol/Src/basic_ProtocolData.h"
#include "../Protocol/Src/basic_ProtocolHandler.h"

using namespace std;
bool g_isLoop = true;
bool g_print = false;

class cPacketHandler : public basic::c2s_ProtocolHandler
{
public:
	cPacketHandler() {}
	virtual ~cPacketHandler() {}

	virtual bool ReqLogin(basic::ReqLogin_Packet &packet)
	{
		cout << "ReqLogin " << endl;
		return true;
	}

	virtual bool Work(basic::Work_Packet &packet)
	{
		if (g_print)
		{
			cout << "Work" << endl;
			cout << "\tworkid = " << packet.workId << endl;
			cout << "\tstatus = " << packet.status << endl;
			cout << "\tstatusValue = " << packet.statusValue << endl;
			cout << "\t";
			for (auto v : packet.path)
				cout << v << ",";
			cout << endl;
			cout << "\tname = " << packet.name << endl;
			cout << packet.name << endl;
		}

		return true;
	}

	virtual bool AckWork(basic::AckWork_Packet &packet)
	{
		if (g_print)
			cout << "ReqLoading " << packet.result << "\n";
		return true;
	}

	virtual bool func5(basic::func5_Packet &packet)
	{
		if (g_print)
			cout << "recv basic::func5_Packet - " << packet.str << endl;
		return true;
	}

	virtual bool func6(basic::func6_Packet &packet)
	{
		if (g_print)
			cout << "recv basic::func6_Packet - " << packet.value << endl;
		return true;
	}
};


BOOL CtrlHandler(DWORD fdwCtrlType)
{
	g_isLoop = false;
	return TRUE;
}


int main(const int argc, const char *argv[])
{
	cout << "<bind port=\"10001\">" << endl << endl;

	int port = 10001;
	if (argc >= 2)
	{
		port = atoi(argv[2]);
	}

	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		cout << "SetConsoleCtrlHandler failed, code : " << GetLastError() << endl;
		return -1;
	}

	network2::cNetController netController;
	network2::cUdpServer server;
	cPacketHandler handler;

	server.AddProtocolHandler(&handler);

	if (!netController.StartUdpServer(&server, port, network2::DEFAULT_PACKETSIZE, 1024, 1))
	{
		cout << "Error Server Bind" << endl;
	}

	common::cTimer timer;
	timer.Create();

	int procPacketCnt = 0;
	double oldT = timer.GetSeconds();
	while (g_isLoop)
	{
		procPacketCnt += netController.Process(0.01f);

		double curT = timer.GetSeconds();
		if (curT - oldT > 1.f)
		{
			cout << "procPacketCnt = " << procPacketCnt << endl;
			procPacketCnt = 0;
			oldT = curT;
		}
	}

	netController.Clear();
}

