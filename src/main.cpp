#include "GameController.h"

int main ()
{
	GameController* gameController = new GameController();
	
	while (!gameController->CheckShouldClose())
	{
		gameController->Update();
		gameController->Draw();
	}

	delete gameController;
	
	return 0;
}
