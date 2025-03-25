#include "GameController.h"
#include "raylib.h"
#include "Debug.h"


GameController::GameController(const float& windowWidth, const float& windowHeight,  const int& frameRate)
{
	this->deltaTime = 0.0f;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->frameRate = frameRate;

	this->clock = new Clock(Vector2{windowWidth / 2.0f, 10.0f});
	this->player = new Player(Vector2{windowWidth / 2.0f, windowHeight - 100.0f});
	
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(frameRate);
	
	InitWindow(static_cast<int>(windowWidth), static_cast<int>(windowHeight), Strings::Utility::gameTitle);
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
	player->Draw();
		
	EndDrawing();
}


void GameController::Update()
{
	deltaTime = GetFrameTime();
	
	clock->Update(deltaTime);
	player->Update(deltaTime);
}

bool GameController::CheckShouldClose() const
{
	return WindowShouldClose();
}

void GameController::LoadAssets() const
{
	player->Load();
}