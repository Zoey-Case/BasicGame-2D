#pragma once

#include <utility>

#include "Character/CharacterBase.h"

namespace Character
{
	class Obstacle : public CharacterBase
	{
	public:
		Obstacle(const Vector2& startingPosition = Vector2{10.0f, 10.0f},
				 const float& startingSpeed = 50.0f,
				 const float& startingRotation = 0.0f,
				 const Color& startingColor = WHITE,
				 const float& startingScale = 1.0f);

		~Obstacle();

		void Update(const float& deltaTime = GetFrameTime()) override;
		void Load() override;
		void Move(const Vector2& moveInput, const float& deltaTime) override;

		void Destroy();
		bool IsDestroyed();
	
	private:
		float rotationSpeed;
		bool isDestroyed;
	};
}