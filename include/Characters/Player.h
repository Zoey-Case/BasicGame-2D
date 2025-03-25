#pragma once

#include "CharacterBase.h"
#include "Timers/BaseTimer.h"

namespace Characters
{
	class Player : public CharacterBase
	{
	public:
		Player(const Vector2& startingPosition = Vector2{10.0f, 10.0f},
			   const float& startingSpeed = 250.0f,
			   const float& startingRotation = 0.0f,
			   const Color& startingColor = WHITE,
			   const float& startingScale = 1.0f);

		~Player() override;

		void Update(const float& deltaTime) override;
		void Draw() const override;
		void Load() override;
		void Move(const float& deltaTime) override;

	private:
		Vector2 GetMoveInput();
		void Fire();

		Timers::BaseTimer* weaponTimer;
	};
}
