#pragma once

namespace Timers
{
	class BaseTimer
	{
	public:
		BaseTimer(const float& startTimeInSeconds = 0.0f);
		virtual ~BaseTimer() = default;

		virtual void Update(const float& deltaTime);
		virtual void Reset();

		float GetTimeInSeconds() const;
		int GetMinutes() const;
		int GetSeconds() const;

	protected:
		float time;
		float totalTimeInSeconds;
		int minutes;
		int seconds;
	};
}