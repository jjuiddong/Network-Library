#include "pch.h"
#include "../ChatCore/chating.h"

using namespace std;

int g_isLoop = true;

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	g_isLoop = false;
	return TRUE;
}

int main()
{
	// port ¼³Á¤
	const int bindPort = 4001;

	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		cout << "SetConsoleCtrlHandler failed, code : " << GetLastError() << endl;
		return -1;
	}

	cChatingServer cChatServer;

	network2::cNetController nCtrl;

	if (!nCtrl.StartTcpServer(&cChatServer.m_server, bindPort
		, network2::DEFAULT_PACKETSIZE, 1024, 1))
	{
		cout << "Bind Error Occurred!!\n";
		return -1;
	}

	common::cTimer timer;
	timer.Create();

	double oldT = timer.GetSeconds();

	while (g_isLoop)
	{
		const double curT = timer.GetSeconds();
		const float dt = (float)(curT - oldT);
		oldT = curT;

		nCtrl.Process(dt);

		Sleep(10);
	}
}
