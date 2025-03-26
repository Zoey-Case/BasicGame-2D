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

		virtual void Update(const float& deltaTime = GetFrameTime());
		virtual void Move(const Vector2& moveInput, const float& deltaTime);
		
		virtual void Draw() const;
		virtual void Load();

	protected:
		const char* texturePath;
		Texture texture;
		
		Color color;
		float scale;
		
		Vector2 position;
		float moveSpeed;
		float rotation;
	};
}
