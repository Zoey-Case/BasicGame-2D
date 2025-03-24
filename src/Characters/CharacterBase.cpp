#include "Characters/CharacterBase.h"

namespace Characters
{
	CharacterBase::CharacterBase(const char* texturePath, const Vector2 position, const float rotation,
								 const float scale, const Color color, const int layer)
	{
		this->texture = LoadTexture(texturePath);
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
		this->color = color;
		this->layer = layer;
	}

	CharacterBase::~CharacterBase()
	{
		UnloadTexture(this->texture);
	}

	void CharacterBase::Update(const float& deltaTime) {}
	void CharacterBase::Draw() const {}
}
