#include "Timers/BaseTimer.h"

namespace Timers
{
	BaseTimer::BaseTimer(const float& startTimeInSeconds)
	{
		this->time = startTimeInSeconds;
		this->totalTimeInSeconds = startTimeInSeconds;

		this->minutes = 0;
		
		while (time > 1.0f)
		{
			time -= 1.0f;
			this->minutes++;
		}
		
		this->seconds = static_cast<int>(time);
	}

	void BaseTimer::Reset()
	{
		time = 0.0f;
		totalTimeInSeconds = 0.0f;
		minutes = 0;
		seconds = 0;
	}

	float BaseTimer::GetTimeInSeconds() const { return totalTimeInSeconds; }

	int BaseTimer::GetMinutes() const { return minutes; }

	int BaseTimer::GetSeconds() const { return seconds; }

	void BaseTimer::Update(const float& deltaTime)
	{
		time += deltaTime;
		totalTimeInSeconds += deltaTime;
		
		if (time >= 1.0f)
		{
			time -= 1.0f;
			seconds++;
			
			if (seconds >= 60)
			{
				minutes++;
				seconds = 0;
			}
		}
	}
}