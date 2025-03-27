#include "ObstacleController.h"

ObstacleController::~ObstacleController() { Cleanup(); }

void ObstacleController::Update(const float& deltaTime)
{
	if (obstacles.empty()) { return; }

	for (int index = static_cast<int>(obstacles.size() - 1); index >= 0; index--)
	{
		if (obstacles[index]->IsDestroyed())
		{
			obstacles.pop_back();
			continue;
		}

		obstacles[index]->Update();
		obstacles[index]->Draw();
	}
}

void ObstacleController::SpawnObstacle()
{
	obstacles.emplace(obstacles.begin(), new Obstacle(Vector2{static_cast<float>(GetRandomValue(0, GetScreenWidth())), -25.0f}));
	obstacles.front()->Load();
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
