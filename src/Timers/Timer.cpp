#include "Timers/Timer.h"

namespace Timers
{
	Timer::Timer() : BaseTimer()
	{
		timeElapsed = 0.0f;
	}

	float Timer::GetTimeElapsed() const
	{
		return timeElapsed;
	}

	Timer::~Timer()
	{
		BaseTimer::~BaseTimer();
	}

	void Timer::Update(const float& deltaTime)
	{
		timeElapsed += deltaTime;
		BaseTimer::Update(deltaTime);
	}

	void Timer::Draw() const { BaseTimer::Draw(); }

	void Timer::Reset()
	{
		timeElapsed = 0.0f;
		
		BaseTimer::Reset();
	}
}
