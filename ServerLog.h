#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include "ServerApp.h"
#include "Timer.h"



namespace TestApp
{
	class ServerLog
	{
	private:
		std::string _filename;
		ServerApp* _server;
		std::ofstream *_log;
		Timer* _timer;
		std::thread *_log_thread;
	
		static void Shutdown(ServerApp* server, unsigned int log_record_count);
	public:
		ServerLog(ServerApp *s);
		static void writeToLog(Customer* ptr, unsigned int log_record_count, std::ofstream* log);
		static void startLog(Timer* timer, ServerApp* server, std::ofstream* log);
		Timer* getTimer();
		ServerApp* getServer();
		std::ofstream * getLog();
	};
}

