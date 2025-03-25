#pragma once

namespace Timers
{
	class BaseTimer
	{
	public:
		BaseTimer(const float& startTimeInSeconds = 0.0f);
		virtual ~BaseTimer() = default;

		virtual void Update(const float& deltaTime);
		virtual void Draw() const;
		virtual void Reset();

		int GetMinutes() const;
		int GetSeconds() const;

	protected:
		float time;
		int minutes;
		int seconds;
	};
}