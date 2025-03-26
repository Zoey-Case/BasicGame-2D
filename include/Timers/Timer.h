#pragma once

#include "Timers/BaseTimer.h"

namespace Timers
{
	class Timer : public BaseTimer
	{
	public:
		Timer();
		~Timer() override;
		
		void Update(const float& deltaTime) override;
		void Draw() const override;
		void Reset() override;

		float GetTimeElapsed() const;

	private:
		float timeElapsed;
	};
}
