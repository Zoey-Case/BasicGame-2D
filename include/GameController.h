#pragma once
#include "Timers/Clock.h"

using namespace Timers;


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
	float deltaTime;
	int frameRate;
	int windowWidth;
	int windowHeight;
};
