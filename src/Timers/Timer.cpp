#include "Timers/Timer.h"

namespace Timers
{
	Timer::Timer(const float& startTimeInSeconds) : BaseTimer(startTimeInSeconds) {}

	Timer::~Timer()
	{
		BaseTimer::~BaseTimer();
	}

	void Timer::Update(const float& deltaTime)
	{
		BaseTimer::Update(deltaTime);
	}

	void Timer::Reset()
	{
		BaseTimer::Reset();
	}
}
