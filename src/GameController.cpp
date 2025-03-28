﻿#include "GameController.h"
#include "raylib.h"
#include "Debug.h"


GameController::GameController(const float& windowWidth, const float& windowHeight,  const int& frameRate)
{
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	this->frameRate = frameRate;
	this->gameOver = false;
	this->gameWon = false;
	this->score = 0;

	this->clock = new Clock(Vector2{windowWidth / 2.0f, 10.0f});
	this->player = new Player(Vector2{windowWidth / 2.0f - 75.0f, windowHeight - 100.0f});
	this->obstacleController = new ObstacleController();
	this->scoreCard = new ScoreCard(windowWidth - 150, 20);
	
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(frameRate);
	
	InitWindow(static_cast<int>(windowWidth), static_cast<int>(windowHeight), Strings::Utility::gameTitle);
}

GameController::~GameController()
{
	CleanUpObjects();
	
	CloseWindow();
}

void GameController::Update(const float& deltaTime)
{
	clock->Update(deltaTime);
	
	CheckCollisions();
	obstacleController->Update(deltaTime);
	player->Update(deltaTime);
}

void GameController::FixedUpdate(const float& deltaTime)
{
	if (int newScore = obstacleController->GetNumDestroyed(); newScore > scoreCard->GetScore())
	{
		scoreCard->SetScore(newScore);
	}
}

bool GameController::CheckShouldClose() const
{
	return WindowShouldClose();
}

bool GameController::IsGameOver() const
{
	return gameOver;
}

void GameController::LoadAssets() const
{
	player->Load();
}

void GameController::CheckCollisions()
{
	const Rectangle playerRect = player->GetCollider();
	const std::vector<Rectangle> projectileRects = player->GetProjectileColliders();
	const std::vector<Rectangle> obstacleRects = obstacleController->GetColliders();
	
	for (int oIndex = static_cast<int>(obstacleRects.size() - 1); oIndex >= 0; oIndex--)
	{
		if (CheckCollisionRecs(obstacleRects[oIndex], playerRect))
		{
			gameOver = true;
			return;
		}
		
		for (int pIndex = static_cast<int>(projectileRects.size() - 1); pIndex >= 0; pIndex--)
		{
			if (CheckCollisionRecs(obstacleRects[oIndex], projectileRects[pIndex]))
			{
				Debug::Warning("COLLISION DETECTED!");
				
				player->RemoveProjectile(pIndex);
				obstacleController->RemoveObstacle(oIndex);
				
				break;
			}
		}
	}
}

void GameController::DrawGameScreen()
{
	BeginDrawing();
	ClearBackground(BLACK);
	
	DrawFPS(10, 10);
	
	obstacleController->Draw();
	player->Draw();

	clock->Draw();
	scoreCard->Draw();
	
	EndDrawing();
}

void GameController::DrawGameOver()
{
	if (gameWon)
	{
		DrawEndScreen(
			"GAME WON!",
			static_cast<int>(windowWidth / 2.0f - 50.0f),
			static_cast<int>(windowHeight / 2));
		return;
	}
		
	DrawEndScreen(
			"GAME OVER",
			static_cast<int>(windowWidth / 2.0f - 50.0f),
			static_cast<int>(windowHeight / 2));
}

void GameController::DrawEndScreen(const char* text, const int& textX, const int& textY)
{
	std::string scoreText = Strings::Stats::obstaclesDestroyed + std::to_string(scoreCard->GetScore());

	BeginDrawing();
	ClearBackground(BLACK);
	
	DrawFPS(10, 10);
	DrawText(text, textX - 50, textY, 32, WHITE);
	DrawText(scoreText.c_str(), textX - 120, textY + 40, 24, WHITE);

	EndDrawing();
}

void GameController::CleanUpObjects()
{
	delete this->clock;
	this->clock = nullptr;
	
	delete this->player;
	this->player = nullptr;
	
	delete this->obstacleController;
	this->obstacleController = nullptr;

	delete this->scoreCard;
	this->scoreCard = nullptr;
}