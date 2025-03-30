#pragma once

#include <utility>

#include "Character/CharacterBase.h"

namespace Character
{
	class Obstacle : public CharacterBase
	{
	public:
		Obstacle(const Vector2& startingPosition = Vector2{static_cast<float>(GetScreenWidth()) / 2.0f, -25.0f},
				 const float& startingSpeed = static_cast<float>(GetRandomValue(50, 75)),
				 const float& startingRotation = 0.0f,
				 const Color& startingColor = WHITE,
				 const float& startingScale = 1.0f);

		~Obstacle() override;

		void Update(const float& deltaTime = GetFrameTime()) override;
		void Load() override;
		void Move(Vector2 input, const float& deltaTime) override;
		
		void Rotate(const float& rotationAdd, const float& deltaTime);

		void Destroy();
		bool IsDestroyed();
	
	private:
		float rotationSpeed;
		bool isDestroyed;
	};
}