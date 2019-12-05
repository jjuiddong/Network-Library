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
	// port, ip 설정
	const int connectionPorts = 4001;
	string connectionIp = "127.0.0.1";

	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE)) 
	{
		cout << "SetConsoleCtrlHandler failed, code : " << GetLastError() << endl;
		return -1;
	}

	cChatingClient cChatClient;

	network2::cNetController nCtrl;

	if (!nCtrl.StartTcpClient(&cChatClient.m_client, connectionIp.c_str(), connectionPorts))
	{
		cout << "Bine Error Occurred!!\n";
		return -1;
	}

	while (g_isLoop) 
	{
		nCtrl.Process(0.01f);
		cChatClient.Process();
		Sleep(10);
	}

	nCtrl.Clear();

	return 1;
}