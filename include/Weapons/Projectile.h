#pragma once

#include "raylib.h"
#include "Timers/Timer.h"

namespace Weapons
{
	class Projectile
	{
	public:
		Projectile(const Vector2& position, const char* texturePath);
		~Projectile();

		void Update(const float& deltaTime);
		void Draw() const;
		void Load();

		bool IsDeleted() const;
		Rectangle GetCollider() const;
		void Delete();
		
	private:
		Vector2 position;
		float rotation;
		float speed;
		float scale;
		Color color;
		bool isDeleted;
		Sound clip;

		const char* texturePath;
		Texture texture;
	};
}
