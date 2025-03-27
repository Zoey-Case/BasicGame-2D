#include "Characters/Player.h"

#include "Debug.h"
#include "Strings/StringLibrary.h"
#include "Weapons/Projectile.h"

namespace Characters
{
	Player::Player(const Vector2& startingPosition, const float& startingSpeed, const float& startingRotation,
				   const Color& startingColor, const float& startingScale) :
		CharacterBase(Strings::Texture::spaceship, startingPosition, startingSpeed,
					  startingRotation, startingColor, startingScale)
	{
		this->projectileTexturePath = Strings::Texture::laser;
		this->fireRate = 0.5f;
		this->fireTimer = new Timers::Timer(fireRate);
	}

	Player::~Player()
	{
		CharacterBase::~CharacterBase();
	}


	void Player::Update(const float& deltaTime)
	{
		fireTimer->Update(deltaTime);

		MoveAndRotate(deltaTime);
		
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
	}

	void Player::Move(const Vector2& moveInput, const float& deltaTime)
	{
		CharacterBase::Move(Vector2{moveInput.x * moveSpeed, moveInput.y * moveSpeed}, deltaTime);
	}

	void Player::Rotate(const float& newRotation, const float& deltaTime)
	{
		CharacterBase::Rotate(newRotation, deltaTime);
	}

	void Player::MoveAndRotate(const float& deltaTime)
	{
		Vector2 moveInput = GetMoveInput();
		Move(moveInput, deltaTime);

		if (moveInput.x > 0.0f) { Rotate(10.0f, deltaTime); }
		else if (moveInput.x < 0.0f) { Rotate(-10.0f, deltaTime); }
		else { Rotate(0.0f, deltaTime); }
	}

	std::vector<Rectangle> Player::GetProjectileColliders() const
	{
		std::vector<Rectangle> rects = {};

		if (!projectiles.empty())
		{
			for (const Weapons::Projectile* projectile : projectiles)
			{
				rects.push_back(projectile->GetRect());
			}
		}
	
		return rects;
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
