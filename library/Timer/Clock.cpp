#include "Clock.h"
clock_t TimerBaseClock::GetTicks() 
{
		if (IsStarted()) {
			tick_t now = clock();
			tick_t dt  = (now - m_start);
			return dt;
		}
		return 0;
	}