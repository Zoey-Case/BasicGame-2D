#pragma once

#include "BackgroundController.h"
#include "ObstacleController.h"
#include "Character/Player.h"
#include "Timers/Clock.h"
#include "Stats/ScoreCard.h"
#include "Audio/MusicPlayer.h"

namespace Controller
{
	class GameController
	{
	public:
		explicit GameController(const int& winningScore, const float& windowWidth = 1280, const float& windowHeight = 720, const int& frameRate = 60);
		~GameController();

		void Update(const float& deltaTime);
		void FixedUpdate(const float& deltaTime);
		void StartScreen();
		void DrawGameScreen();
		void DrawGameOver(const float& deltaTime);

		bool CheckAssetsLoaded() const;
		bool CheckShouldStart() const;
		bool CheckShouldClose();
		bool IsGameOver() const;
		void TryReset();
		void LoadAssets();

	private:
		void InitializeRaylib() const;
		void CheckCollisions();
		void DrawStartScreen(const char* text, const int& textX, const int& textY) const;
		void DrawEndScreen(const char* text, const int& textX, const int& textY);
		void InitializeObjects();
		void CleanUpObjects();
		void TryUpdateScore();
	
		Timers::Clock* clock = nullptr;
		Character::Player* player = nullptr;
		ObstacleController* obstacleController = nullptr;
		Stats::ScoreCard* scoreCard = nullptr;
		Audio::MusicPlayer* musicPlayer = nullptr;
		BackgroundController* backgroundController = nullptr;
	
		int frameRate;
		float windowWidth;
		float windowHeight;
		bool assetsLoaded;
		bool gameOver;
		bool gameWon;
		bool startGame;
		int winningScore;
	};
}