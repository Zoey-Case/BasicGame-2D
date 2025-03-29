#pragma once

#include <vector>

#include "Animation/Animation.h"
#include "Character/Obstacle.h"
#include "Timers/Timer.h"

namespace Controller
{
	class ObstacleController
	{
	public:
		ObstacleController(const float& spawnTime = 1.5f);
		~ObstacleController();

		void Update(const float& deltaTime);
		void Draw();
	
		void SpawnObstacle();
		int GetNumSpawned() const;
		int GetNumDestroyed() const;
		bool RunningAnimation() const;
	
		std::vector<Rectangle> GetColliders() const;
		void RemoveObstacle(const int& index);

	private:
		void SpawnExplosion(const float& xPos, const float& yPos);
		void DespawnExplosion(const int& index);
		
		void Cleanup();
		
		Timers::Timer* timer;
		std::vector<Character::Obstacle*> obstacles;
		std::vector<Animation::Animation*> explosions;

		int numSpawned;
		int numDestroyed;
		float spawnTime;
		bool animationRunning;
	};
}