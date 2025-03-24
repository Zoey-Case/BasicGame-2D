#include "Characters/Player.h"

namespace Characters
{
	Player::Player(const char* texturePath, const Vector2& position, const float& rotation,
				   const float& scale, const Color& color, const int& layer)
					: CharacterBase(texturePath, position, rotation, scale, color, layer) {}

	Player::~Player()
	{
		CharacterBase::~CharacterBase();
	}

	void Player::Update(const float& deltaTime)
	{
		CharacterBase::Update(deltaTime);
	}

	void Player::Draw() const
	{
		CharacterBase::Draw();
		DrawTextureEx(texture, position, rotation, scale, color);
	}
}
