#include "Controller/BackgroundController.h"

#include "Debug.h"
#include "Strings/StringLibrary.h"

namespace Controller
{
	BackgroundController::BackgroundController(const Vector2& windowSize, const float& starsPerSecond, const float& moveSpeed)
	{
		this->windowSize = windowSize;
		this->starsPerSecond = starsPerSecond;
		this->moveSpeed = moveSpeed;
		
		timer = new Timers::Timer();
	}
	
	BackgroundController::~BackgroundController()
	{
		CleanUp();
	}

	void BackgroundController::Update(const float& deltaTime)
	{
		timer->Update(deltaTime);

		if (timer->GetTimeInSeconds() >= (1.0f / this->starsPerSecond))
		{
			AddStar();
			timer->Reset();
		}
		
		if (!stars.empty()) { MoveStars(deltaTime); }
	}

	void BackgroundController::Draw() const
	{
		if (stars.empty()) { return; }
		DrawStars();
	}

	void BackgroundController::Load(const int& startingMin, const int& startingMax)
	{
		int startNum = GetRandomValue(startingMin, startingMax);

		for (int index = 0; index < startNum; index++)
		{
			std::pair star = {
				LoadTexture(Strings::Texture::star),
				Vector2{
					static_cast<float>(GetRandomValue(0, static_cast<int>(windowSize.x))),
					static_cast<float>(GetRandomValue(-25.0f, static_cast<int>(windowSize.y)))
				}
			};

			stars.emplace(stars.begin(), star);
		}
	}

	void BackgroundController::MoveStars(const float& deltaTime)
	{
		for (int index = static_cast<int>(stars.size()) - 1; index >= 0; index--)
		{
			stars[index].second.y += moveSpeed * deltaTime;

			TryRemoveStar(index);
		}
	}

	void BackgroundController::DrawStars() const
	{
		for (int index = static_cast<int>(stars.size()) - 1; index >= 0; index--)
		{
			DrawTextureV(stars[index].first, stars[index].second, WHITE);
		}
	}

	void BackgroundController::AddStar()
	{
		std::pair star = {
			LoadTexture(Strings::Texture::star),
			Vector2{static_cast<float>(GetRandomValue(0, static_cast<int>(windowSize.x))), -25.0f}};

		stars.emplace(stars.begin(), star);
	}

	void BackgroundController::TryRemoveStar(const int& index)
	{
		if (stars[index].second.y > windowSize.y)
		{
			UnloadTexture(stars[index].first);
			stars.erase(stars.begin() + index);
		}
	}

	void BackgroundController::CleanUp()
	{
		for (int index = static_cast<int>(stars.size()) - 1; index >= 0; index--)
		{
			UnloadTexture(stars[index].first);
			stars.pop_back();
		}
	}
}
