#pragma once
#include <string>

#include "BaseTimer.h"
#include "raylib.h"
#include "Strings/StringLibrary.h"

namespace Timers
{
	class Clock : public BaseTimer
	{
	public:
		Clock(const Vector2& position, const char* font = Strings::Font::STORM_FAZE.c_str(), const float& fontSize = 32.0f, const float& fontSpacing = 5.0f, const Color& fontColor = WHITE, const float& startTimeInSeconds = 0.0f);
		~Clock() override;
		
		void Update(const float& deltaTime) override;
		void Draw() const override;

	private:
		void UpdateTimeText();
		
		std::string timeText;
		
		Vector2 position;
		Font font;
		float fontSize;
		float fontSpacing;
		Color fontColor;
	};
}
