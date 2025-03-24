#pragma once
#include "raylib.h"

namespace Characters
{
	class CharacterBase
	{
	public:
		CharacterBase(const char* texturePath, Vector2 position, float rotation,
					  float scale, Color color, int layer);
		
		virtual ~CharacterBase();

		virtual void Update(const float& deltaTime);
		virtual void Draw() const;

	protected:
		Color color;
		int layer;
		float rotation;
		float scale;
		Texture texture;
		Vector2 position;
	};
}
