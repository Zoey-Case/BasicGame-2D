#include "Stats/ScoreCard.h"
#include "Strings/StringLibrary.h"

#include <string>

namespace Stats
{
	ScoreCard::ScoreCard(const int& xPos, const int& yPos, const int& fontSize, const Color& color)
	{
		this->xPos = xPos;
		this->yPos = yPos;
		this->fontSize = fontSize;
		this->color = color;
		this->text = Strings::Stats::score;

		this->score = 0;
	}

	void ScoreCard::Draw()
	{
		std::string displayText = text + std::to_string(score);
		DrawText(displayText.c_str(), xPos, yPos, fontSize, color);
	}

	int ScoreCard::GetScore() const { return score; }

	void ScoreCard::SetScore(const int& num) { score = num; }
}