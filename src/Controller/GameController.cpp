#include "Controller/GameController.h"
#include "raylib.h"
#include "Debug.h"

namespace Controller
{
	GameController::GameController(const float& windowWidth, const float& windowHeight,  const int& frameRate)
	{
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;

		this->frameRate = frameRate;
		this->gameOver = false;
		this->gameWon = false;
		this->winningScore = 2;

		this->clock = new Timers::Clock(Vector2{windowWidth / 2.0f, 10.0f});
		this->player = new Character::Player(Vector2{windowWidth / 2.0f - 75.0f, windowHeight - 100.0f});
		this->obstacleController = new ObstacleController();
		this->scoreCard = new Stats::ScoreCard(static_cast<int>(windowWidth) - 150, 20);
		this->musicPlayer = new Audio::MusicPlayer(Strings::Audio::music);
		this->backgroundController = new BackgroundController(Vector2{windowWidth, windowHeight});
	
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
		musicPlayer->Update(deltaTime);
		backgroundController->Update(deltaTime);
		
		clock->Update(deltaTime);
	
		CheckCollisions();
		obstacleController->Update(deltaTime);
		player->Update(deltaTime);
	}

	void GameController::FixedUpdate(const float& deltaTime)
	{
		const int newScore = obstacleController->GetNumDestroyed();

		if (newScore >= winningScore && !obstacleController->RunningAnimation())
		{
			gameOver = true;
			gameWon = true;
		}

		if (newScore > scoreCard->GetScore()) { scoreCard->SetScore(newScore); }
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
		backgroundController->Load();
		musicPlayer->Load();
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

		backgroundController->Draw();
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
		backgroundController->Draw();
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

		delete this->musicPlayer;
		this->musicPlayer = nullptr;

		delete this->backgroundController;
		this->backgroundController = nullptr;
	}

	void GameController::TryUpdateScore()
	{
		const int newScore = obstacleController->GetNumDestroyed();

		if (newScore >= winningScore && !obstacleController->RunningAnimation())
		{
			gameOver = true;
			gameWon = true;
		}

		if (newScore > scoreCard->GetScore()) { scoreCard->SetScore(newScore); }
	}
}
