#pragma once
#include "Characters/Player.h"
#include "Timers/Clock.h"

using namespace Characters;
using namespace Timers;


class GameController
{
public:
	explicit GameController(const float& windowWidth = 1280, const float& windowHeight = 720, const int& frameRate = 60);
	~GameController();

	void Draw();
	void Update();
	
	bool CheckShouldClose() const;
	void LoadAssets() const;

private:
	Clock* clock = nullptr;
	Player* player;
	
	float deltaTime;
	int frameRate;
	float windowWidth;
	float windowHeight;
};
