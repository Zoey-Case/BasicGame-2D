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

		this->texture = Texture();
		timer = new Timers::Timer();
	}

	void Projectile::Update(const float& deltaTime)
	{
		timer->Update(deltaTime);
		if (this->position.y < -50.0f || timer->GetTimeElapsed() >= 5.0f) { Delete(); }
		else { position.y -= speed * deltaTime; }
	}

	void Projectile::Draw() const
	{
		DrawTextureEx(texture, position, rotation, scale, color);
	}

	void Projectile::Load()
	{
		texture = LoadTexture(texturePath);
		position = Vector2{
			position.x - static_cast<float>(texture.width) / 2.0f,
			position.y - static_cast<float>(texture.height) / 2.0f};
	}

	bool Projectile::IsDeleted() const
	{
		return isDeleted;
	}

	void Projectile::Delete()
	{
		delete timer;
		UnloadTexture(texture);
		this->isDeleted = true;
	}
}
