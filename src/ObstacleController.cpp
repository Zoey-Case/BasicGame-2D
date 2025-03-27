#include "ObstacleController.h"

ObstacleController::ObstacleController(const float& spawnTime)
{
	this->timer = new Timers::Timer();
	this->spawnTime = spawnTime;
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
	
	if (obstacles.empty()) { return; }

	for (int index = static_cast<int>(obstacles.size() - 1); index >= 0; index--)
	{
		if (obstacles[index]->IsDestroyed())
		{
			obstacles.pop_back();
			continue;
		}

		obstacles[index]->Update();
	}
}

void ObstacleController::Draw()
{
	for (int index = static_cast<int>(obstacles.size() - 1); index >= 0; index--)
	{
		obstacles[index]->Draw();
	}
}

void ObstacleController::SpawnObstacle()
{
	obstacles.emplace(obstacles.begin(), new Obstacle(Vector2{static_cast<float>(GetRandomValue(0, GetScreenWidth())), -25.0f}));
	obstacles.front()->Load();
}

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

void ObstacleController::RemoveObstacle(const int& obstacleIndex)
{
	obstacles[obstacleIndex]->Destroy();
	delete obstacles[obstacleIndex];
	obstacles.erase(obstacles.begin() + obstacleIndex);
}

void ObstacleController::Cleanup()
{
	if (obstacles.empty()) { return; }

	for (int index = static_cast<int>(obstacles.size() - 1); index >= 0; index--)
	{
		obstacles[index]->Destroy();
		obstacles.pop_back();
	}
}
