//
// 2019-12-12, jjuiddong
// TCP network transaction test
//
#include "pch.h"
#include "../Protocol/Src/basic_Protocol.h"
#include "../Protocol/Src/basic_ProtocolData.h"
#include "../Protocol/Src/basic_ProtocolHandler.h"

using namespace std;
bool g_isLoop = true;
bool g_isPrint = false;

class cTestClient : public basic::s2c_ProtocolHandler
{
public:
	cTestClient() : m_state(0), m_isLogin(false) {}

	virtual bool AckLogin(basic::AckLogin_Packet &packet) 
	{ 
		m_isLogin = true;
		if (g_isPrint)
			cout << "recv basic::AckLogin" << endl;
		return true;
	}

	virtual bool func1(basic::func1_Packet &packet)
	{
		if (g_isPrint)
			cout << "recv basic::func1" << endl;
		return true;
	}

	virtual bool func2(basic::func2_Packet &packet)
	{
		if (g_isPrint)
			cout << "recv basic::func2" << endl;
		return true;
	}

	virtual bool func3(basic::func3_Packet &packet)
	{
		if (g_isPrint)
			cout << "recv basic::func3" << endl;
		return true;
	}

	virtual bool func4(basic::func4_Packet &packet)
	{
		if (g_isPrint)
			cout << "recv basic::func4" << endl;
		return true;
	}


public:
	bool m_isLogin;
	int m_state;
	network2::cTcpClient m_client;
	basic::c2s_Protocol m_protocol;
};


BOOL CtrlHandler(DWORD fdwCtrlType)
{
	g_isLoop = false;
	return TRUE;
}

void TransactionTest(const string &ip, const int port);

int main(const int argc, const char *argv[])
{
	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		cout << "SetConsoleCtrlHandler failed, code : " << GetLastError() << endl;
		return -1;
	}

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

	const int MAX_THREAD = 5;
	std::thread ths[MAX_THREAD];
	for (int i=0; i < MAX_THREAD; ++i)
		ths[i] = std::thread(TransactionTest, ip, port);

	for (int i = 0; i < MAX_THREAD; ++i)
		ths[i].join();
}


void TransactionTest(const string &ip, const int port)
{
	const int MAX_TCPCLIENT = 100;

	network2::cNetController netController;
	vector<cTestClient*> testClients;

	for (int i = 0; i < MAX_TCPCLIENT; ++i)
	{
		cTestClient *client = new cTestClient();
		client->m_client.AddProtocolHandler(client);
		client->m_client.RegisterProtocol(&client->m_protocol);
		testClients.push_back(client);

		if (!netController.StartTcpClient(&client->m_client, ip.c_str(), port
			, network2::DEFAULT_PACKETSIZE, network2::DEFAULT_MAX_PACKETCOUNT
			, 1, -1, false))
		{
			cout << "Error Client Connection" << endl;
		}
	}

	common::cTimer timer;
	timer.Create();
	double oldT = timer.GetSeconds();
	int sendPacketCnt = 0;

	while (g_isLoop)
	{
		netController.Process(0.01f);

		for (uint i = 0; i < testClients.size(); ++i)
		{
			auto &tclient = testClients[i];
			auto &client = testClients[i]->m_client;
			auto &protocol = testClients[i]->m_protocol;
			if (client.IsConnect())
			{
				switch (tclient->m_state)
				{
				case 0:
					if (!tclient->m_isLogin)
						protocol.ReqLogin(network2::SERVER_NETID, "client");

					tclient->m_state = 1;
					break;

				case 1:
					if (!tclient->m_isLogin)
						break;

					if (g_isPrint)
						cout << "client" << i << " send func5 " << endl;

					sendPacketCnt++;
					protocol.func5(network2::SERVER_NETID, "Test");
					tclient->m_state = 2;
					break;

				case 2:
					if (g_isPrint)
						cout << "client" << i << " send func6 " << endl;
					sendPacketCnt++;
					protocol.func6(network2::SERVER_NETID, 100);
					tclient->m_state = 3;
					break;

				case 3:
				{
					if (g_isPrint)
						cout << "client" << i << " Work " << endl;
					vector<int> path;
					for (int i = 1; i < 10; ++i)
						path.push_back(i);
					sendPacketCnt++;
					protocol.Work(network2::SERVER_NETID, 1, 2, 3, path, "work str");
					tclient->m_state = 0;
				}
				break;
				}
			}
			else if (client.IsFailConnection())
			{
				client.ReConnect();
			}

			client.Process();
		}

		Sleep(1);

		double curT = timer.GetSeconds();
		if (curT - oldT > 1.f)
		{
			cout << "sendPacketCnt = " << sendPacketCnt << endl;
			sendPacketCnt = 0;
			oldT = curT;
		}
	}

	netController.Clear();

	for (uint i = 0; i < testClients.size(); ++i)
		delete testClients[i];
	testClients.clear();
}
