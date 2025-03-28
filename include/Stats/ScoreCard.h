#pragma once

#include "raylib.h"
#include <string>

namespace Stats
{
	class ScoreCard
	{
	public:
		ScoreCard(const int& xPos, const int& yPos, const int& fontSize = 24, const Color& color = WHITE);
		~ScoreCard() = default;

		void Draw();

		int GetScore() const;
		void SetScore(const int& num);
	
	private:
		int xPos;
		int yPos;
		int fontSize;
		Color color;

		int score;
		std::string text;
	};
}