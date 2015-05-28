#include "ServerApp.h"

namespace TestApp
{

	ServerApp::ServerApp() : sa_server_active(true)
	{
		//todo
	}

	bool ServerApp::isServerActive()
	{
		std::lock_guard<std::mutex> lock(m_mtx);
		return sa_server_active;
	}

	void ServerApp::ShutdownServer()
	{
		std::lock_guard<std::mutex> lock(m_mtx);
		this->sa_server_active = false;
	}

	void ServerApp::addClient(Customer* ptr)
	{
		std::lock_guard<std::mutex> lock(m_mtx);
		if (ptr == nullptr) return;
		sa_PQ_PCUS.push(ptr);
	}

	Customer* ServerApp::withdrawClient()
	{
		std::lock_guard<std::mutex> lock(m_mtx);
		Customer* temp = sa_PQ_PCUS.top();
		sa_PQ_PCUS.pop();

		return temp;
	}

	bool ServerApp::isPQempty()
	{
		std::lock_guard<std::mutex> lock(m_mtx);
		return sa_PQ_PCUS.empty();
	}

	unsigned int ServerApp::getClients()
	{
		std::cout << ">>>Enter count of customers :";
		unsigned int N;
		do
		{
			std::cin >> N;
			if (N <= 0)
			{
				std::cout << "\nInput data is invalid, enter integer :";
				continue;
			}
			if (isdigit(N))
			{
				"\nYou must enter a positive integer :";
				std::cin.clear();
				while (!std::cin.eof())
				{
					std::cin.get();
				}
				continue;
			}
		} while (!N);
		
		return N;
	}

}

