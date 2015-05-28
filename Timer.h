#pragma once
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
namespace TestApp
{
	class Timer
	{
	protected:
		DWORD _last_start_time;
		DWORD _idle_time;
		bool _is_idle;
	public:
		Timer();
		void setIdleTime(unsigned int msec);
		void start();
		bool isIdle();
	};
}