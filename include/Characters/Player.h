#pragma once

#include "CharacterBase.h"

namespace Characters
{
	class Player : public CharacterBase
	{
	public:
		Player(const char* texturePath, const Vector2& position, const float& rotation = 180.0f,
			   const float& scale = 1.0f, const Color& color = WHITE, const int& layer = 1.0f);

		~Player() override;

		void Update(const float& deltaTime) override;
		void Draw() const override;
	};
}