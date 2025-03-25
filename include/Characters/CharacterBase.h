#pragma once
#include "raylib.h"

namespace Characters
{
	class CharacterBase
	{
	public:
		explicit CharacterBase(const char* texturePath, const Vector2& position, const float& moveSpeed,
							   const float& rotation,
							   const Color& color,
							   const float& scale);
		virtual ~CharacterBase();

		virtual void Update(const float& deltaTime);
		virtual void Move(const float& deltaTime);
		
		virtual void Draw() const;
		virtual void Load();

	protected:
		const char* texturePath;
		Texture texture = Texture();
		
		Color color;
		float scale;
		
		Vector2 position;
		Vector2 moveVector = Vector2{0.0f, 0.0f};
		float moveSpeed;
		float rotation;
	};
}
