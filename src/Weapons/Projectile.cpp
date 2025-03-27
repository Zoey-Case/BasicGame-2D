#include "Weapons/Projectile.h"
#include "Strings/StringLibrary.h"

namespace Weapons
{
	Projectile::Projectile(const Vector2& position, const char* texturePath)
	{
		this->position = position;
		this->texturePath = texturePath;
		
		this->rotation = 0.0f;
		this->speed = 300.0f;
		this->scale = 1.0f;
		this->color = WHITE;
		this->isDeleted = false;

		texture = Texture();
	}

	void Projectile::Update(const float& deltaTime)
	{
		if (this->position.y < -50.0f) { Delete(); }
		else { position.y -= speed * deltaTime; }
	}

	void Projectile::Draw() const
	{
		const Vector2 drawPosition = Vector2{
			position.x - static_cast<float>(texture.width) / 2.0f,
			position.y - static_cast<float>(texture.height) / 2.0f};
		
		DrawTextureEx(texture, drawPosition, rotation, scale, color);
	}

	void Projectile::Load()
	{
		texture = LoadTexture(texturePath);
	}

	bool Projectile::IsDeleted() const
	{
		return isDeleted;
	}

	Rectangle Projectile::GetRect() const
	{
		return Rectangle{
			position.x - static_cast<float>(texture.width) / 2.0f,
			position.y - static_cast<float>(texture.height) / 2.0f,
			static_cast<float>(texture.width),
			static_cast<float>(texture.height)};
	}

	void Projectile::Delete()
	{
		UnloadTexture(texture);
		this->isDeleted = true;
	}
}
