#include "Animation/Animation.h"

#include "Debug.h"

namespace Animation
{
	Animation::Animation(const float& refreshRate, const Vector2& position, const std::vector<std::string>& texturePaths, const Color& color)
	{
		this->refreshRate = refreshRate;
		this->textureIndex = 0;
		this->position = position;
		this->texture = Texture();
		this->sourceRect = Rectangle{0.0f, 0.0f, 0.0f, 0.0f};

		for (const std::string& texturePath : texturePaths)
		{
			this->texturePaths.push_back(texturePath);
		}

		this->color = color;

		this->timer = new Timers::Timer();
		this->isFinished = false;

		this->clip = LoadSound(Strings::Audio::explosion.c_str());
		PlaySound(clip);
	}

	Animation::~Animation()
	{
		UnloadSound(clip);
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
		const Rectangle destinationRect =
			Rectangle{position.x, position.y, sourceRect.width, sourceRect.height};

		const float rotation = 0.0f;
		
		DrawTexturePro(
			texture,
			sourceRect,
			destinationRect,
			Vector2{sourceRect.width / 2.0f, sourceRect.height / 2.0f},
			rotation,
			WHITE);
	}

	void Animation::Load()
	{
		UpdateCurrentTexture();
	}

	bool Animation::IsFinished() const { return isFinished; }

	void Animation::UpdateCurrentTexture()
	{
		texture = LoadTexture(texturePaths[textureIndex].c_str());
		textureIndex++;

		sourceRect.width = static_cast<float>(texture.width);
		sourceRect.height = static_cast<float>(texture.height);
		
		if (textureIndex >= static_cast<int>(texturePaths.size())) { isFinished = true; }
	}
}
