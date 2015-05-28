#define _CRT_SECURE_NO_WARNINGS

#include "ClientApp.h"
#include "ServerLog.h"

int main()
{
	TestApp::ServerApp *SA = new TestApp::ServerApp();
	unsigned int N = SA->getClients();

	TestApp::ServerLog *SL = new TestApp::ServerLog(SA);
	TestApp::ClientApp *CA = new TestApp::ClientApp(SA,N);

	std::thread t1(TestApp::ClientApp::sendClientData, CA->getCount(), CA->getServer());
	std::thread t2(TestApp::ServerLog::startLog, SL->getTimer(), SL->getServer(), SL->getLog());


	//int c;
	//do
	//{
	//	c = getchar();
	//} while (c != 10); //10 Enter

	t1.join();
	t2.join();

	system("pause");

	return 0;
}