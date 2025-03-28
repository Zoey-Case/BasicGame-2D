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
		virtual void Move(const Vector2& moveInput, const float& deltaTime);
		virtual void Rotate(const float& newRotation, const float& deltaTime);
		
		const char* texturePath;
		Texture texture;
		
		Color color;
		float scale;
		
		Vector2 position;
		float moveSpeed;
		float rotation;
	};
}
