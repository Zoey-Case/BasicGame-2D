#include "Controller/GameController.h"
#include "raylib.h"
#include "Debug.h"

namespace Controller
{
	GameController::GameController(const int& winningScore, const float& windowWidth, const float& windowHeight,  const int& frameRate)
	{
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;
		this->frameRate = frameRate;
		this->winningScore = winningScore;
		this->startGame = false;

		backgroundController = new BackgroundController(Vector2{windowWidth, windowHeight});
		
		InitializeRaylib();
		InitializeObjects();
	}

	GameController::~GameController()
	{
		delete this->backgroundController;
		this->backgroundController = nullptr;
		
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

	void GameController::StartScreen()
	{
		DrawStartScreen(
		Strings::Utility::gameTitle, 
			static_cast<int>(windowWidth / 2.0f - 170.0f),
			static_cast<int>(windowHeight / 2.0f - 50.0f));
		
		if (IsKeyPressed(KEY_ENTER))
		{
			backgroundController->Load();
			
			startGame = true;
		}
	}

	void GameController::LoadAssets()
	{
		musicPlayer->Load();
		player->Load();
		
		assetsLoaded = true;
	}

	void GameController::InitializeRaylib() const
	{
		SetConfigFlags(FLAG_WINDOW_HIGHDPI);
		SetTargetFPS(frameRate);
		InitWindow(static_cast<int>(windowWidth), static_cast<int>(windowHeight), Strings::Utility::gameTitle);
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

	void GameController::DrawStartScreen(const char* text, const int& textX, const int& textY) const
	{
		BeginDrawing();
		ClearBackground(BLACK);
	
		DrawFPS(10, 10);

		DrawText(text, textX - 50, textY, 32, WHITE);
		DrawText(Strings::Utility::moveControls, textX - 15, textY + 50, 24, WHITE);
		DrawText(Strings::Utility::fireControls, textX + 55, textY + 75, 24, WHITE);
		DrawText(Strings::Utility::startPrompt, textX - 8, textY + 160, 24, WHITE);
	
		EndDrawing();
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

	void GameController::DrawGameOver(const float& deltaTime)
	{
		backgroundController->Update(deltaTime);
		
		if (gameWon)
		{
			DrawEndScreen(
				"GAME WON!",
				static_cast<int>(windowWidth / 2.0f - 50.0f),
				static_cast<int>(windowHeight / 2.0f - 50.0f));
			return;
		}

		DrawEndScreen(
				"GAME OVER",
				static_cast<int>(windowWidth / 2.0f - 50.0f),
				static_cast<int>(windowHeight / 2.0f - 50.0f));
	}

	bool GameController::CheckAssetsLoaded() const { return assetsLoaded; }

	bool GameController::CheckShouldStart() const { return startGame; }
	
	bool GameController::CheckShouldClose()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			CleanUpObjects();
			return true;
		}
		
		return false;
	}

	bool GameController::IsGameOver() const { return gameOver; }

	void GameController::TryReset()
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			CleanUpObjects();
			InitializeObjects();
		}
	}

	void GameController::DrawEndScreen(const char* text, const int& textX, const int& textY)
	{
		std::string scoreText = Strings::Stats::obstaclesDestroyed + std::to_string(scoreCard->GetScore());
		
		BeginDrawing();
		ClearBackground(BLACK);
	
		DrawFPS(10, 10);
		backgroundController->Draw();
		DrawText(text, textX - 50, textY, 32, WHITE);
		DrawText(scoreText.c_str(), textX - 125, textY + 40, 24, WHITE);
		DrawText(Strings::Utility::restartPrompt, textX - 160, textY + 100, 24, WHITE);
		DrawText(Strings::Utility::exitPrompt, textX - 95, textY + 140, 24, WHITE);

		EndDrawing();
	}

	void GameController::InitializeObjects()
	{
		gameOver = false;
		gameWon = false;
		assetsLoaded = false;

		clock = new Timers::Clock(Vector2{windowWidth / 2.0f, 10.0f});
		player = new Character::Player();
		obstacleController = new ObstacleController();
		scoreCard = new Stats::ScoreCard(static_cast<int>(windowWidth) - 150, 20);
		musicPlayer = new Audio::MusicPlayer(Strings::Audio::music);
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
