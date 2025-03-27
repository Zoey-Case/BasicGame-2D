#include "GameController.h"

int main ()
{
	GameController* gameController = new GameController();
	gameController->LoadAssets();
	float fixedDeltaTime = 0.0f;
	const float updateDelay = 1.0f/60.0f;
	
	while (!gameController->CheckShouldClose())
	{
		if (!gameController->IsGameOver())
		{
			float deltaTime = GetFrameTime();
			fixedDeltaTime += deltaTime;

			if (!gameController->IsGameOver())
			{
				gameController->Update(deltaTime);
				if (fixedDeltaTime >= updateDelay)
				{
					gameController->FixedUpdate(fixedDeltaTime);
					fixedDeltaTime = 0.0f;
				}
			}
			
			gameController->DrawGameScreen();
			continue;
		}
		
		gameController->DrawGameOver();
	}

	delete gameController;
	
	return 0;
}
