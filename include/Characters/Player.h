#pragma once

#include <vector>

#include "CharacterBase.h"
#include "Weapons/Projectile.h"

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

		void Update(const float& deltaTime = GetFrameTime()) override;
		void Draw() const override;
		void Load() override;
		void Move(const Vector2& moveInput, const float& deltaTime) override;

	private:
		void UpdateProjectiles(const float& deltaTime);
		void SpawnProjectile();
		void RemoveProjectile();
		
		Vector2 GetMoveInput();
		void Fire();
		const char* projectileTexturePath;

		std::vector<Weapons::Projectile*> projectiles;
	};
}
