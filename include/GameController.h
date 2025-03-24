#pragma once
#include "Characters/Player.h"
#include "Timers/Clock.h"

using namespace Timers;
using namespace Characters;


class GameController
{
public:
	explicit GameController(const int& windowWidth = 1280, const int& windowHeight = 720, const int& frameRate = 60);
	~GameController();

	void Draw();
	void Update();
	
	bool CheckShouldClose() const;

private:
	Clock* clock = nullptr;
	Player* player = nullptr;
	
	float deltaTime;
	int frameRate;
	int windowWidth;
	int windowHeight;
};
