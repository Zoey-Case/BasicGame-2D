#include "Characters/Player.h"
#include "Strings/StringLibrary.h"

namespace Characters
{
	Player::Player(const Vector2& startingPosition, const float& startingSpeed, const float& startingRotation,
				   const Color& startingColor, const float& startingScale) :
		CharacterBase(Strings::Texture::spaceship, startingPosition, startingSpeed, startingRotation, startingColor, startingScale)
	{
		weaponTimer = new Timers::BaseTimer();
	}

	Player::~Player()
	{
		CharacterBase::~CharacterBase();
	}


	void Player::Update(const float& deltaTime)
	{
		Move(deltaTime);
	}

	void Player::Draw() const
	{
		CharacterBase::Draw();
	}

	void Player::Load()
	{
		CharacterBase::Load();
	}

	void Player::Move(const float& deltaTime)
	{
		Vector2 moveInput = GetMoveInput();
		moveVector = Vector2{moveInput.x * moveSpeed, moveInput.y * moveSpeed};

		CharacterBase::Move(deltaTime);
	}

	Vector2 Player::GetMoveInput()
	{
		Vector2 input = Vector2{
			static_cast<float>(
				(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) - (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))),
			static_cast<float>(
				(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) - (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)))};

		float magnitude = sqrtf(input.x * input.x + input.y * input.y);
		
		if (magnitude > 0.0f)
		{
			input.x /= magnitude;
			input.y /= magnitude;
		}
		
		return input;
	}
}
