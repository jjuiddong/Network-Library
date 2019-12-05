//
// 2019-12-05, jjuiddong
// network core test client
//
#include "pch.h"
#include "../Protocol/Src/basic_Protocol.h"
#include "../Protocol/Src/basic_ProtocolData.h"
#include "../Protocol/Src/basic_ProtocolHandler.h"

using namespace std;
bool g_isLoop = true;

class cPacketHandler : public basic::s2c_ProtocolHandler
{
public:
	cPacketHandler() {}
	virtual ~cPacketHandler() {}

	virtual bool func1(basic::func1_Packet &packet) 
	{ 
		cout << "recv basic::func1_Packet" << endl;
		return true; 
	}

	virtual bool func2(basic::func2_Packet &packet)
	{
		cout << "recv basic::func2_Packet" << endl;
		return true;
	}

	virtual bool func3(basic::func3_Packet &packet)
	{
		cout << "recv basic::func3_Packet" << endl;
		return true;
	}

	virtual bool func4(basic::func4_Packet &packet)
	{
		cout << "recv basic::func4_Packet" << endl;
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
	cout << "<ip=\"127.0.0.1\"> <port=\"10001\">" << endl << endl;

	string ip = "127.0.0.1";
	int port = 10001;
	if (argc >= 2)
	{
		ip = argv[1];
	}
	if (argc >= 3)
	{
		port = atoi(argv[2]);
	}

	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		cout << "SetConsoleCtrlHandler failed, code : " << GetLastError() << endl;
		return -1;
	}

	network2::cNetController netController;
	network2::cTcpClient client;
	cPacketHandler handler;
	basic::c2s_Protocol m_protocol;

	client.AddProtocolHandler(&handler);
	client.RegisterProtocol(&m_protocol);

	if (!netController.StartTcpClient(&client, ip.c_str(), port))
	{
		cout << "Error Client Connection" << endl;
	}

	int state = 0;
	while (g_isLoop)
	{
		netController.Process(0.01f);

		if (client.IsConnect())
		{
			switch (state)
			{
			case 0:
				cout << "send func5 " << endl;
				m_protocol.func5(network2::SERVER_NETID, "Test");
				Sleep(1000);
				state = 1;
				break;

			case 1:
				cout << "send func6 " << endl;
				m_protocol.func6(network2::SERVER_NETID, 100);
				Sleep(1000);
				state = 2;
				break;

			case 2:
			{
				cout << "Work " << endl;
				vector<int> path;
				for (int i=1; i < 10; ++i)
					path.push_back(i);
				m_protocol.Work(network2::SERVER_NETID, 1, 2, 3, path, "work str");
				Sleep(1000);
				state = 0;
			}
			break;
			}
		}
	}

	netController.Clear();
}

