#include "Characters/CharacterBase.h"

namespace Characters
{
	CharacterBase::CharacterBase(const char* texturePath, const Vector2& position, const float& moveSpeed,
								 const float& rotation, const Color& color, const float& scale)
	{
		this->texturePath = texturePath;
		this->texture = Texture();
		this->moveSpeed = moveSpeed;
		this->position = position;
		this->rotation = rotation;
		this->color = color;
		this->scale = scale;
	}

	CharacterBase::~CharacterBase()
	{
		UnloadTexture(texture);
	}

	void CharacterBase::Update(const float& deltaTime) { /*FULLY VIRTUAL METHOD*/ }

	void CharacterBase::Draw() const
	{
		DrawTextureEx(texture, position, rotation, scale, color);
	}

	void CharacterBase::Load()
	{
		texture = LoadTexture(texturePath);
	}

	Rectangle CharacterBase::GetCollider() const
	{
		return Rectangle{
			position.x,
			position.y,
			static_cast<float>(texture.width),
			static_cast<float>(texture.height)};
	}

	void CharacterBase::Move(const Vector2& moveInput, const float& deltaTime)
	{
		position.x += moveInput.x * deltaTime;
		position.y += moveInput.y * deltaTime;
	}

	void CharacterBase::Rotate(const float& newRotation, const float& deltaTime)
	{
		rotation = newRotation;
	}
}
