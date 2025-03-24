#include "GameController.h"
#include "raylib.h"
#include "Debugging/Debug.h"

using namespace Debugging;


GameController::GameController(const int& windowWidth, const int& windowHeight,  const int& frameRate)
{
	this->deltaTime = 0.0f;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->frameRate = frameRate;

	this->clock =
		new Clock(
			Vector2{static_cast<float>(windowWidth) / 2.0f, 10.0f}
			);
	
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(frameRate);
	
	InitWindow(windowWidth, windowHeight, Strings::Utility::GameTitle);
}

GameController::~GameController()
{
	CloseWindow();
}

void GameController::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	
	DrawFPS(10.0f, 10.0f);
	clock->Draw();
		
	EndDrawing();
}


void GameController::Update()
{
	deltaTime = GetFrameTime();
	clock->Update(deltaTime);
}

bool GameController::CheckShouldClose() const
{
	return WindowShouldClose();
}
