#include "Character/Player.h"

#include "Debug.h"
#include "Strings/StringLibrary.h"
#include "Timers/Timer.h"
#include "Weapons/Projectile.h"

namespace Character
{
	Player::Player(const Vector2& startingPosition, const float& startingSpeed, const float& startingRotation,
				   const Color& startingColor, const float& startingScale) :
		CharacterBase(Strings::Texture::spaceship, startingPosition, startingSpeed,
					  startingRotation, startingColor, startingScale)
	{
		this->projectileTexturePath = Strings::Texture::laser;
		this->fireRate = 0.25f;
		this->fireTimer = new Timers::Timer(fireRate);
		this->yBounds = Vector2{0.0f, static_cast<float>(GetScreenHeight())};
	}

	Player::~Player()
	{
		CharacterBase::~CharacterBase();
	}


	void Player::Update(const float& deltaTime)
	{
		fireTimer->Update(deltaTime);

		Move(GetMoveInput(), deltaTime);
		
		if (fireTimer->GetTimeInSeconds() >= fireRate)
		{
			TryFire();
		}
		
		if (!projectiles.empty()) { UpdateProjectiles(deltaTime); }

		CharacterBase::Update(deltaTime);
	}

	void Player::Load()
	{
		CharacterBase::Load();

		yBounds.x += sourceRect.height / 2.0f;
		yBounds.y -= sourceRect.height / 2.0f;
	}

	void Player::Move(Vector2 input, const float& deltaTime)
	{
		if (input.x > 0.0f) { rotation = 5.0f; }
		else if (input.x < 0.0f) { rotation = -5.0f; }
		else { rotation = 0.0f; }
		
		if (position.y + input.y >= yBounds.y)
		{
			input.y = 0.0f;
			position.y = yBounds.y;
		}
		else if (position.y + input.y <= yBounds.x)
		{
			input.y = 0.0f;
			position.y = yBounds.x;
		}
		
		CharacterBase::Move(input, deltaTime);
	}

	std::vector<Rectangle> Player::GetProjectileColliders() const
	{
		std::vector<Rectangle> colliders = {};

		if (!projectiles.empty())
		{
			for (const Weapons::Projectile* projectile : projectiles)
			{
				colliders.push_back(projectile->GetCollider());
			}
		}
	
		return colliders;
	}

	void Player::RemoveProjectile(const int& projectileIndex)
	{
		projectiles[projectileIndex]->Delete();
		delete projectiles[projectileIndex];
		projectiles.erase(projectiles.begin() + projectileIndex);
	}

	void Player::UpdateProjectiles(const float& deltaTime)
	{
		for (int index = static_cast<int>(projectiles.size() - 1); index >= 0; index--)
		{
			if (projectiles[index]->IsDeleted())
			{
				projectiles.pop_back();
				continue;
			}
			
			projectiles[index]->Update(deltaTime);
			projectiles[index]->Draw();
		}
	}

	void Player::SpawnProjectile()
	{
		projectiles.emplace(projectiles.begin(), new Weapons::Projectile(position, this->projectileTexturePath));
		projectiles.front()->Load();
	}

	Vector2 Player::GetMoveInput()
	{
		Vector2 input = Vector2{
			static_cast<float>(
				(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) - (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))),
			static_cast<float>(
				(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) - (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)))};

		if (const float magnitude = sqrtf(input.x * input.x + input.y * input.y); magnitude > 0.0f)
		{
			input.x /= magnitude;
			input.y /= magnitude;
		}
		
		return input;
	}

	void Player::Fire()
	{
		SpawnProjectile();
		
		Debug::Log("INSTANTIATE PROJECTILE #" + std::to_string(projectiles.size()) + "!");
	}

	void Player::TryFire()
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			Fire();
			fireTimer->Reset();
		}
	}
}
