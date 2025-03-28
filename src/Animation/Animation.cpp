#include "Animation/Animation.h"

namespace Animation
{
	Animation::Animation(const float& refreshRate, const float& xPos, const float& yPos, const std::vector<char*> texturePaths, const Color& color)
	{
		this->refreshRate = refreshRate;
		this->textureIndex = 0;
		this->position = Vector2{xPos, yPos};

		for (char* texturePath : texturePaths)
		{
			this->texturePaths.push_back(texturePath);
		}

		this->color = color;

		this->timer = new Timers::Timer();
		isFinished = false;
	}

	Animation::~Animation()
	{
		delete timer;
	}

	void Animation::Update(const float& deltaTime)
	{
		if (isFinished) { return; }
		
		timer->Update(deltaTime);
		
		if (timer->GetTimeInSeconds() < refreshRate) { return; }

		if (textureIndex < static_cast<int>(texturePaths.size())) { UpdateCurrentTexture(); }

		timer->Reset();
	}

	void Animation::Draw() const
	{
		DrawTexture(texture, static_cast<int>(position.x), static_cast<int>(position.y), color);
	}

	void Animation::Load() { UpdateCurrentTexture(); }

	bool Animation::IsFinished() const { return isFinished; }

	void Animation::UpdateCurrentTexture()
	{
		texture = LoadTexture(texturePaths[textureIndex]);
		textureIndex++;
		if (textureIndex >= static_cast<int>(texturePaths.size())) { isFinished = true; }
	}
}
