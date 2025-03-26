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
	
	void CharacterBase::Move(const Vector2& moveInput, const float& deltaTime)
	{
		position.x += moveInput.x * deltaTime;
		position.y += moveInput.y * deltaTime;
	}

	void CharacterBase::Draw() const
	{
		const Vector2 drawPos =
			{position.x - (static_cast<float>(texture.width) / 2.0f),
			 position.y - (static_cast<float>(texture.height) / 2.0f)};
		
		DrawTextureEx(texture, drawPos, rotation, scale, color);
	}

	void CharacterBase::Load()
	{
		texture = LoadTexture(texturePath);
	}
}
