#pragma once

#include "Timers/BaseTimer.h"

namespace Timers
{
	class Timer : public BaseTimer
	{
	public:
		Timer(const float& startTimeInSeconds = 0.0f);
		~Timer() override;
		
		void Update(const float& deltaTime) override;
		void Reset() override;
	};
}
