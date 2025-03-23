#pragma once

namespace Timers
{
	class BaseTimer
	{
	public:
		BaseTimer(const float& startTimeInSeconds = 0.0f);
		virtual ~BaseTimer();

		virtual void Update(const float& deltaTime);
		virtual void Draw() const;

	protected:
		float time;
		int minutes;
		int seconds;
	};
}