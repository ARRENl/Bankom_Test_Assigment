#include "Timer.h"

namespace TestApp
{
	Timer::Timer() : _last_start_time(0), _idle_time(0), _is_idle(false) {}

	void Timer::setIdleTime(unsigned int msec)
	{
		_idle_time = 2000;
	}

	void Timer::start()
	{
		_last_start_time = timeGetTime();
	}

	bool Timer::isIdle()
	{
		DWORD temptime = timeGetTime();
		if ((temptime - _last_start_time) > _idle_time) _is_idle = true;
		return _is_idle;
	}
}
