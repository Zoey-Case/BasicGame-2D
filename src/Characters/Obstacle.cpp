#include "Characters/Obstacle.h"
#include "Strings/StringLibrary.h"
#include "Obstacle.h"

namespace Characters
{
	Obstacle::Obstacle(const Vector2& startingPosition, const float& startingSpeed, const float& startingRotation,
					   const Color& startingColor, const float& startingScale) :
		CharacterBase(Strings::Texture::meteor, startingPosition, startingSpeed,
					  startingRotation, startingColor, startingScale)
	{
		rotationSpeed = static_cast<float>(GetRandomValue(0, 45));
		isDestroyed = false;
	}
	
	Obstacle::~Obstacle()
	{
		CharacterBase::~CharacterBase();
	}

	void Obstacle::Update(const float &deltaTime)
	{
		Move(Vector2{moveSpeed, 0.0f}, deltaTime);
	}
	
	void Obstacle::Draw() const
	{
		CharacterBase::Draw();
	}
	
	void Obstacle::Load()
	{
		CharacterBase::Load();
	}
	
	void Obstacle::Move(const Vector2 &moveInput, const float &deltaTime)
	{
		CharacterBase::Move(Vector2{moveInput.x, moveInput.y}, deltaTime);
	}
}

void Characters::Obstacle::Destroy()
{
	isDestroyed = true;
	UnloadTexture(texture);
}

bool Characters::Obstacle::IsDestroyed()
{
	return isDestroyed;
}
