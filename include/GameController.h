#pragma once
#include "Timers/Clock.h"


class GameController
{
public:
	explicit GameController(const int& windowWidth = 1280, const int& windowHeight = 720, const int& frameRate = 60);
	~GameController();

	void Draw();
	void Update();
	
	bool CheckShouldClose() const;

private:
	Timers::Clock* clock = nullptr;
	float deltaTime;
	int frameRate;
	int windowWidth;
	int windowHeight;
};
