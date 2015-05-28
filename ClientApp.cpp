#include "ClientApp.h"

namespace TestApp
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::thread;

	ClientApp::ClientApp(ServerApp* s,unsigned int n)
	{
		_server = s;
		ca_clients_count = n;
	}

	//ClientApp::~ClientApp()
	//{

	//}


	void ClientApp::sendClientData(unsigned int count, ServerApp* server)
	{
		for (unsigned int i = 0; i < count; i++)
		{
			Customer *ptr = new Customer();
			server->addClient(ptr);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}

	unsigned int ClientApp::getCount()
	{
		return ca_clients_count;
	}

	ServerApp* ClientApp::getServer()
	{
		return _server;
	}
}