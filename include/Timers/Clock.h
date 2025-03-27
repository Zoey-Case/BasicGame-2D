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
		Clock(const Vector2& position, const char* font = Strings::Font::stormFaze, const float& fontSize = 28.0f,
			  const float& fontSpacing = 5.0f, const Color& fontColor = WHITE, const float& startTimeInSeconds = 0.0f);
		~Clock() override = default;
		
		void Update(const float& deltaTime) override;
		void Draw() const;

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
