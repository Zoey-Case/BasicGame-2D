#pragma once
#include "raylib.h"

namespace Character
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
		
		void Draw() const;
		virtual void Load();

		Rectangle GetCollider() const;
		Vector2 GetPosition() const;

	protected:
		virtual void Move(Vector2 input, const float& deltaTime);
		
		const char* texturePath;
		Texture texture;
		
		Color color;
		float scale;
		
		Vector2 position;
		Vector2 xBounds;
		Rectangle sourceRect;
		float moveSpeed;
		float rotation;
	};
}
