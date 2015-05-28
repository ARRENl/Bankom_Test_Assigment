#include "ServerLog.h"

namespace TestApp
{
	using std::string;
	using std::endl;

	ServerLog::ServerLog(ServerApp *s)
	{
		srand(time(NULL));
		_server = s;
		_filename = "Log.txt";
		_log = new std::ofstream(_filename.c_str());
		_timer = new Timer();
		_timer->setIdleTime(2000);
	}

	void ServerLog::writeToLog(Customer* ptr, unsigned int log_record_count, std::ofstream* log)
	{
		*log << "#" << static_cast<int>(log_record_count + 1) << endl;
		*log << "recording time = " << GetTickCount() << endl;
		*log << "id = " << std::hex << ptr->getClientID() << endl;
		*log << "priority = " << std::dec << static_cast<short>(ptr->getClientPriority()) << endl;
		*log << "ticks = " << ptr->getTimeStamp() << endl;
		*log << "/////////////////////////////////" << endl << endl;

	}

	void ServerLog::startLog(Timer* timer, ServerApp* server, std::ofstream* log)
	{
		unsigned int log_record_count = 0;
		timer->start();
		bool SD = false;
		while (server->isServerActive())
		{
			if (timer->isIdle() && !SD)
			{
				SD = true;
				ServerLog::Shutdown(server, log_record_count);
			}
			if (server->isPQempty()) continue;
			else
			{
				timer->start();
				Customer* ptr = server->withdrawClient();
				ServerLog::writeToLog(ptr, log_record_count, log);
				log_record_count++;
			}			
		}
		log->close();
	}

	void ServerLog::Shutdown(ServerApp* server, unsigned int log_record_count)
	{
			std::cout << "Clients writed to log = " << log_record_count
				<< ". \n";
	
		server->ShutdownServer();
	}

	Timer* ServerLog::getTimer()
	{
		return _timer;
	}
	ServerApp* ServerLog::getServer()
	{
		return _server;
	}
	std::ofstream * ServerLog::getLog()
	{
		return _log;
	}
}