#ifndef ServerApp_h
#define ServerApp_h

#include <queue>
#include <mutex>
#include "Customer.h"

namespace TestApp
{
	class CompareCustomerptr {
	public:
		bool operator()(Customer* lhs, Customer* rhs)
		{
			return !(lhs->getClientPriority() < rhs->getClientPriority());
		}
	};

	using std::mutex;
	typedef std::priority_queue<Customer, std::vector<Customer*>, CompareCustomerptr> stdpq;

	class ServerApp
	{
	private:
		bool sa_server_active;
		mutex m_mtx;
		stdpq sa_PQ_PCUS;
	public:
		ServerApp();
		void addClient(Customer* ptr);
		Customer* withdrawClient();
		bool isServerActive();
		void ShutdownServer();
		bool isPQempty();
		unsigned int getClients();
	};
}

#endif //ServerApp_h
