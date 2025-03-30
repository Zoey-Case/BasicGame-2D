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

		this->clip = LoadSound(Strings::Audio::laser.c_str());
		PlaySound(clip);

		this->texture = Texture();
		this->sourceRect = Rectangle{0.0f, 0.0f, 0.0f, 0.0f};
	}

	Projectile::~Projectile() { UnloadSound(clip); }

	void Projectile::Update(const float& deltaTime)
	{
		if (this->position.y < -50.0f) { Delete(); }
		else { position.y -= speed * deltaTime; }
	}

	void Projectile::Draw() const
	{
		const Rectangle target =
			Rectangle{position.x, position.y, sourceRect.width, sourceRect.height};
		
		DrawTexturePro(
			texture,
			sourceRect,
			target,
			Vector2{sourceRect.width / 2, sourceRect.height / 2},
			rotation,
			WHITE);
	}

	void Projectile::Load()
	{
		texture = LoadTexture(texturePath);

		sourceRect.width = static_cast<float>(texture.width);
		sourceRect.height = static_cast<float>(texture.height);
	}

	bool Projectile::IsDeleted() const
	{
		return isDeleted;
	}

	Rectangle Projectile::GetCollider() const
	{
		return Rectangle{
			position.x - sourceRect.width / 2.0f,
			position.y - sourceRect.height / 2.0f,
			sourceRect.width,
			sourceRect.height};
	}

	void Projectile::Delete()
	{
		UnloadTexture(texture);
		this->isDeleted = true;
	}
}
