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

	clock = new Clock(Vector2{static_cast<float>(windowWidth) / 2.0f, 10.0f});

	player = new Player(
		Strings::Texture::SPACESHIP,
		Vector2{static_cast<float>(windowWidth) / 2.0f, static_cast<float>(windowHeight) - 25.0f});
	
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(frameRate);
	
	InitWindow(windowWidth, windowHeight, Strings::Utility::GameTitle);
}

GameController::~GameController()
{
	delete this->clock;
	delete this->player;
	
	CloseWindow();
}

void GameController::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	
	DrawFPS(10, 10);
	clock->Draw();
	// player->Draw();
		
	EndDrawing();
}


void GameController::Update()
{
	deltaTime = GetFrameTime();
	clock->Update(deltaTime);
	// player->Update(deltaTime);
}

bool GameController::CheckShouldClose() const
{
	return WindowShouldClose();
}
