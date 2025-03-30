#include "Controller/ObstacleController.h"
#include "Strings/StringLibrary.h"

namespace Controller
{
	ObstacleController::ObstacleController(const float& spawnTime)
	{
		this->timer = new Timers::Timer();
		this->spawnTime = spawnTime;
		this->animationRunning = false;

		numSpawned = 0;
		numDestroyed = 0;
	}

	ObstacleController::~ObstacleController() { Cleanup(); }

	void ObstacleController::Update(const float& deltaTime)
	{
		timer->Update(deltaTime);
		if (timer->GetTimeInSeconds() >= spawnTime)
		{
			timer->Reset();
			SpawnObstacle();
		}
	
		if (!obstacles.empty())
		{
			for (int index = static_cast<int>(obstacles.size() - 1); index >= 0; index--)
			{
				if (obstacles[index]->IsDestroyed())
				{
					delete obstacles[index];
					obstacles.pop_back();
					continue;
				}

				obstacles[index]->Update();
			}
		}

		if (!explosions.empty())
		{
			for (int index = static_cast<int>(explosions.size() - 1); index >= 0; index--)
			{
				if (explosions[index]->IsFinished())
				{
					DespawnExplosion(index);
					continue;
				}

				explosions[index]->Update(deltaTime);
			}
		}
	}

	void ObstacleController::Draw()
	{
		if (!obstacles.empty())
		{
			for (int index = static_cast<int>(obstacles.size() - 1); index >= 0; index--)
			{
				obstacles[index]->Draw();
			}
		}

		if (!explosions.empty())
		{
			for (int index = static_cast<int>(explosions.size() - 1); index >= 0; index--)
			{
				explosions[index]->Draw();
			}
		}
	}

	void ObstacleController::SpawnObstacle()
	{
		obstacles.emplace(obstacles.begin(), new Character::Obstacle(Vector2{static_cast<float>(GetRandomValue(0, GetScreenWidth())), -25.0f}));
		obstacles.front()->Load();
		numSpawned++;
	}

	int ObstacleController::GetNumSpawned() const { return numSpawned; }

	int ObstacleController::GetNumDestroyed() const { return numDestroyed; }

	bool ObstacleController::RunningAnimation() const { return animationRunning; }

	std::vector<Rectangle> ObstacleController::GetColliders() const
	{
		std::vector<Rectangle> rects = {};

		if (!obstacles.empty())
		{
			for (int index = 0; index < static_cast<int>(obstacles.size()); index++)
			{
				rects.push_back(obstacles[index]->GetCollider());
			}
		}
	
		return rects;
	}

	void ObstacleController::RemoveObstacle(const int& index)
	{
		Vector2 position = obstacles[index]->GetPosition();
		
		obstacles[index]->Destroy();
		delete obstacles[index];
		obstacles.erase(obstacles.begin() + index);
		numDestroyed++;

		SpawnExplosion(position);
	}

	void ObstacleController::SpawnExplosion(const Vector2& position)
	{
		const std::vector<std::string>& texturePaths = Strings::Animation::explosion;
		const float refreshRate = 1.0f / static_cast<float>(texturePaths.size());
		
		explosions.emplace(explosions.begin(), new Animation::Animation(refreshRate, position, texturePaths));
		animationRunning = true;
	}

	void ObstacleController::DespawnExplosion(const int& index)
	{
		delete explosions[index];
		explosions.erase(explosions.begin() + index);

		if (explosions.empty()) { animationRunning = false; }
	}

	void ObstacleController::Cleanup()
	{
		delete this->timer;
		timer = nullptr;
		
		if (!obstacles.empty())
		{
			for (int index = static_cast<int>(obstacles.size() - 1); index >= 0; index--)
			{
				obstacles[index]->Destroy();
				obstacles.pop_back();
			}
		}

		if (!explosions.empty())
		{
			for (int index = static_cast<int>(explosions.size() - 1); index >= 0; index--)
			{
				delete explosions[index];
				explosions.pop_back();
			}
		}
	}
}
