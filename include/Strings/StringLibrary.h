#pragma once
#include <string>
#include <vector>

namespace Strings
{
	namespace Folder
	{
		const inline char* assets = "Assets/";
	}

	namespace GameObject
	{
		const inline char* playerName = "Player";
		const inline char* obstacleName = "Asteroid";
	}

	namespace Animation
	{
		const inline std::vector<std::string> explosion = {
			"Assets/Animations/Explosion/0.png", "Assets/Animations/Explosion/1.png",
			"Assets/Animations/Explosion/2.png", "Assets/Animations/Explosion/3.png",
			"Assets/Animations/Explosion/4.png", "Assets/Animations/Explosion/5.png",
			"Assets/Animations/Explosion/6.png", "Assets/Animations/Explosion/7.png",
			"Assets/Animations/Explosion/8.png", "Assets/Animations/Explosion/9.png",
			"Assets/Animations/Explosion/10.png", "Assets/Animations/Explosion/11.png",
			"Assets/Animations/Explosion/12.png", "Assets/Animations/Explosion/13.png",
			"Assets/Animations/Explosion/14.png", "Assets/Animations/Explosion/15.png",
			"Assets/Animations/Explosion/16.png", "Assets/Animations/Explosion/17.png",
			"Assets/Animations/Explosion/18.png", "Assets/Animations/Explosion/19.png",
			"Assets/Animations/Explosion/20.png", "Assets/Animations/Explosion/21.png",
			"Assets/Animations/Explosion/22.png", "Assets/Animations/Explosion/23.png",
			"Assets/Animations/Explosion/24.png", "Assets/Animations/Explosion/25.png",
			"Assets/Animations/Explosion/26.png", "Assets/Animations/Explosion/27.png"
		};
	}

	namespace Audio
	{
		const inline std::string explosion = "Assets/Audio/explosion.wav";
		const inline std::string laser = "Assets/Audio/laser.wav";
		const inline std::string music = "Assets/Audio/music.wav";
	}

	namespace Texture
	{
		const inline char* laser = "Assets/Textures/laser.png";
		const inline char* meteor = "Assets/Textures/meteor.png";
		const inline char* spaceship = "Assets/Textures/spaceship.png";
		const inline char* star = "Assets/Textures/star.png";
		const inline char* wabbit = "Assets/Textures/wabbit.png";
	}

	namespace Font
	{
		const inline char* stormFaze = "Assets/Fonts/StormFaze.otf";
	}

	namespace Stats
	{
		const inline char* obstaclesDestroyed = "OBSTACLES DESTROYED: ";
		const inline char* score = "SCORE: ";
	}

	namespace Utility
	{
		const inline char* empty = "";
		const inline char* newLine = "\n";

		const inline char* gameTitle = "MY GAME";
		
		const inline char* windowHeight = "WINDOW HEIGHT: ";
		const inline char* windowWidth = "WINDOW WIDTH: ";
	}
}
