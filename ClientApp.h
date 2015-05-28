#ifndef ClientApp_h
#define ClientApp_h
#include <iostream>
#include <thread>

#include "ServerApp.h"

namespace TestApp
{
	class ClientApp
	{
	private:
		ServerApp* _server;
		unsigned int ca_clients_count;		
	public:
		ClientApp(ServerApp* s, unsigned int n);
		//~ClientApp();
		 unsigned int getCount();
		 ServerApp* getServer();
		 static void sendClientData(unsigned int count, ServerApp* server);
	};
}
#endif //ClientApp_h