#include "Timers/BaseTimer.h"

namespace Timers
{
	BaseTimer::BaseTimer(const float& startTimeInSeconds)
	{
		this->time = startTimeInSeconds;

		this->minutes = 0;
		
		while (time > 1.0f)
		{
			time -= 1.0f;
			this->minutes++;
		}
		
		this->seconds = static_cast<int>(time);
	}

	BaseTimer::~BaseTimer() = default;

	void BaseTimer::Update(const float& deltaTime)
	{
		
	}

	void BaseTimer::Draw() const
	{
		
	}
}