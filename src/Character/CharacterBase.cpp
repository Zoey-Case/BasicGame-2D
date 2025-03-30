#include "Character/CharacterBase.h"

namespace Character
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
		
		this->xBounds = Vector2{0.0f, static_cast<float>(GetScreenWidth())};
		this->sourceRect = Rectangle{0.0f, 0.0f, 0.0f, 0.0f};
	}

	CharacterBase::~CharacterBase()
	{
		UnloadTexture(texture);
	}

	void CharacterBase::Update(const float& deltaTime) { /*FULLY VIRTUAL METHOD*/ }

	void CharacterBase::Draw() const
	{
		const Rectangle target =
			Rectangle{position.x, position.y, sourceRect.width, sourceRect.height};
		
		DrawTexturePro(
			texture,
			sourceRect,
			target,
			Vector2{sourceRect.width / 2.0f, sourceRect.height / 2.0f},
			rotation,
			WHITE);
	}

	void CharacterBase::Load()
	{
		texture = LoadTexture(texturePath);
		
		sourceRect.width = static_cast<float>(texture.width);
		sourceRect.height = static_cast<float>(texture.height);

		xBounds.x += sourceRect.width / 2.0f;
		xBounds.y -= sourceRect.width / 2.0f;
	}

	Rectangle CharacterBase::GetCollider() const
	{
		return Rectangle{
			position.x - sourceRect.width / 2.0f,
			position.y - sourceRect.height / 2.0f,
			sourceRect.width,
			sourceRect.height};
	}

	Vector2 CharacterBase::GetPosition() const { return position; }

	void CharacterBase::Move(Vector2 input, const float& deltaTime)
	{
		if (position.x + input.x >= xBounds.y)
		{
			input.x = 0.0f;
			position.x = xBounds.y;
		}
		else if (position.x + input.x <= xBounds.x)
		{
			input.x = 0.0f;
			position.x = xBounds.x;
		}
		
		position.x += input.x * moveSpeed * deltaTime;
		position.y += input.y * moveSpeed * deltaTime;
	}
}
