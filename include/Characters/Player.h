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
		void Load() override;

		std::vector<Rectangle> GetProjectileColliders() const;
		void RemoveProjectile(const int& projectileIndex);

	private:
		void Move(const Vector2& moveInput, const float& deltaTime) override;
		void Rotate(const float& newRotation, const float& deltaTime) override;
		void MoveAndRotate(const float& deltaTime);
		void UpdateProjectiles(const float& deltaTime);
		void SpawnProjectile();
		
		Vector2 GetMoveInput();
		void Fire();
		void TryFire();
		const char* projectileTexturePath;

		std::vector<Weapons::Projectile*> projectiles;
		Timers::Timer* fireTimer = nullptr;
		float fireRate;
	};
}
