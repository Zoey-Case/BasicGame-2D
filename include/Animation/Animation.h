#pragma once

#include "Strings/StringLibrary.h"
#include <vector>
#include "raylib.h"
#include "Timers/Timer.h"

namespace Animation
{
	class Animation
	{
	public:
		Animation(const float& refreshRate, const Vector2& position, const std::vector<std::string>& texturePaths, const Color& color = WHITE);
		~Animation();

		void Update(const float& deltaTime);
		void Draw() const;

		void Load();
		bool IsFinished() const;

	private:
		void UpdateCurrentTexture();
		
		Timers::Timer* timer;
		float refreshRate;
		int textureIndex;
		Vector2 position;
		Color color;
		bool isFinished;
		Rectangle sourceRect;
		
		Texture texture;
		std::vector<std::string> texturePaths;
		Sound clip;
	};
}
