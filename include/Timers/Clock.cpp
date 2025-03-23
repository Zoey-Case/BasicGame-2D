#include <Timers/Clock.h>

#include "raylib.h"

namespace Timers
{
	Clock::Clock(const Vector2& position, const char* font, const float& fontSize, const float& fontSpacing, const Color& fontColor, const float& startTimeInSeconds) : BaseTimer(startTimeInSeconds)
	{
		UpdateTimeText();
		
		this->position = position;
		
		this->font = LoadFont(font);
		this->fontSize = fontSize;
		this->fontSpacing = fontSpacing;
		this->fontColor = fontColor;
		
	}
	
	Clock::~Clock() = default;

	void Clock::Update(const float& deltaTime)
	{
		time += deltaTime;
		
		if (time >= 1.0f)
		{
			time -= 1.0f;
			seconds++;
			if (seconds >= 60)
			{
				minutes++;
				seconds = 0;
			}

			UpdateTimeText();
		}
	}
	
	void Clock::Draw() const
	{
		DrawTextEx(font, timeText.c_str(), position, fontSize, 0.0f, WHITE);
	}

	void Clock::UpdateTimeText()
	{
		if (minutes == 0) { timeText = std::to_string(seconds); }
		else { timeText = std::to_string(minutes) + " : " + std::to_string(seconds); }
	}
}
