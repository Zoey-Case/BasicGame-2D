#pragma once

#include <vector>

#include "Characters/Obstacle.h"
#include "Timers/Timer.h"

using namespace Characters;

class ObstacleController
{
public:
	ObstacleController(const float& spawnTime = 1.5f);
	~ObstacleController();

	void Update(const float& deltaTime);
	void Draw();
	
	void SpawnObstacle();
	int GetNumDestroyed();
	
	std::vector<Rectangle> GetColliders() const;
	void RemoveObstacle(const int& obstacleIndex);

private:
	void Cleanup();

	Timers::Timer* timer;
	std::vector<Obstacle*> obstacles;

	int numDestroyed;
	float spawnTime;
};