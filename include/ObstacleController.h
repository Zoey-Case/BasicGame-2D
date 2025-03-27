#pragma once
#include <vector>
#include "Characters/Obstacle.h"
#include "Timers/Timer.h"

using namespace Characters;

class ObstacleController
{
public:
	ObstacleController() = default;
	~ObstacleController();

	void Update(const float& deltaTime);
	void SpawnObstacle();

private:
	void Cleanup();

	Timers::Timer* timer;
	std::vector<Obstacle*> obstacles;
};