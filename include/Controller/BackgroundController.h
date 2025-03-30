#pragma once

#include <vector>

#include "raylib.h"
#include "Timers/Timer.h"

namespace Controller
{
	class BackgroundController
	{
	public:
		BackgroundController(const Vector2& windowSize, const float& starsPerSecond = 1.0f, const float& moveSpeed = 2.5f);
		~BackgroundController();

		void Update(const float& deltaTime);
		void Draw() const;
		void Load(const int& startingMin = 50, const int& startingMax = 50);

	private:
		void MoveStars(const float& deltaTime);
		void DrawStars() const;
		void AddStar();
		void TryRemoveStar(const int& index);
		void CleanUp();

		Timers::Timer* timer;
		
		std::vector<std::pair<Texture, Vector2>> stars;
		Vector2 windowSize;
		float moveSpeed;
		float starsPerSecond;
	};
}
