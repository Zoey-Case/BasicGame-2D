#pragma once

#include <vector>

#include "CharacterBase.h"
#include "Timers/Timer.h"
#include "Weapons/Projectile.h"

namespace Character
{
	class Player : public CharacterBase
	{
	public:
		Player(const Vector2& startingPosition = Vector2{static_cast<float>(GetScreenWidth()) / 2.0f, static_cast<float>(GetScreenHeight())},
			   const float& startingSpeed = 250.0f,
			   const float& startingRotation = 0.0f,
			   const Color& startingColor = WHITE,
			   const float& startingScale = 1.0f);

		~Player() override;

		void Update(const float& deltaTime = GetFrameTime()) override;
		void Load() override;

		std::vector<Rectangle> GetProjectileColliders() const;
		void RemoveProjectile(const int& projectileIndex);

	private:
		void Move(Vector2 input, const float& deltaTime) override;
		void UpdateProjectiles(const float& deltaTime);
		void SpawnProjectile();
		
		Vector2 GetMoveInput();
		void Fire();
		void TryFire();

		Vector2 yBounds;
		
		const char* projectileTexturePath;
		std::vector<Weapons::Projectile*> projectiles;
		
		Timers::Timer* fireTimer = nullptr;
		float fireRate;
	};
}
