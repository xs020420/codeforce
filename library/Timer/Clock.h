#include <time.h>

class TimerBaseClock {
public:
	// tick type
	typedef clock_t tick_t;

	// clears the timer
	TimerBaseClock()		{ m_start = -1; }

	// clears the timer
	void Clear()			{ m_start = -1; }

	// returns true if the timer is running
	bool IsStarted() const  { return (m_start != -1); }

	// start the timer
	void Start()            { m_start = clock(); }

	// get elapsed time in ticks
	clock_t GetTicks();
	//extern "C" DLL_PUBLIC tick_t GetTicks();

	// get the number of milliseconds since the timer was started
	unsigned GetMs() {
		return GetMs(GetTicks());
	}
	static unsigned GetMs(tick_t dt) {
		return (unsigned long)((dt + (500/CLOCKS_PER_SEC)) * (1000 / CLOCKS_PER_SEC));
	}
private:
	tick_t m_start;
};