#pragma once
#include <string>
#include <vector>

namespace Strings
{
	namespace Folder
	{
		const inline std::string ANIMATIONS = "Assets/Animations/";
		const inline std::string ASSETS = "Assets/";
		const inline std::string AUDIO = "Assets/Audio/";
		const inline std::string EXPLOSION = "Assets/Animations/Explosion/";
		const inline std::string FONTS = "Assets/Fonts/";
		const inline std::string TEXTURES = "Assets/Textures/";
	}

	namespace GameObject
	{
		const inline char* PlayerName = "Player";
		const inline char* ObstacleName = "OBSTACLE";
	}

	namespace Animation
	{
		const inline std::vector<std::string> EXPLOSION = {
			Folder::EXPLOSION + "0.png", Folder::EXPLOSION + "1.png", Folder::EXPLOSION + "2.png",
			Folder::EXPLOSION + "3.png", Folder::EXPLOSION + "4.png", Folder::EXPLOSION + "5.png",
			Folder::EXPLOSION + "6.png", Folder::EXPLOSION + "7.png", Folder::EXPLOSION + "8.png",
			Folder::EXPLOSION + "9.png", Folder::EXPLOSION + "10.png", Folder::EXPLOSION + "11.png",
			Folder::EXPLOSION + "12.png", Folder::EXPLOSION + "13.png", Folder::EXPLOSION + "14.png",
			Folder::EXPLOSION + "15.png", Folder::EXPLOSION + "16.png", Folder::EXPLOSION + "17.png",
			Folder::EXPLOSION + "18.png", Folder::EXPLOSION + "19.png", Folder::EXPLOSION + "20.png",
			Folder::EXPLOSION + "21.png", Folder::EXPLOSION + "22.png", Folder::EXPLOSION + "23.png",
			Folder::EXPLOSION + "24.png", Folder::EXPLOSION + "25.png", Folder::EXPLOSION + "26.png",
			Folder::EXPLOSION + "27.png"
		};
	}

	namespace Audio
	{
		const inline std::string EXPLOSION = Folder::AUDIO + "explosion.wav";
		const inline std::string LASER = Folder::AUDIO + "laser.wav";
		const inline std::string MUSIC = Folder::AUDIO + "music.wav";
	}

	namespace Texture
	{
		const inline std::string LASER = Folder::TEXTURES + "laser.png";
		const inline std::string METEOR = Folder::TEXTURES + "meteor.png";
		const inline char* SPACESHIP = "Assets/Textures/spaceship.png";
		const inline std::string STAR = Folder::TEXTURES + "star.png";
		const inline std::string WABBIT = Folder::TEXTURES + "wabbit.png";
	}

	namespace Font
	{
		const inline std::string STORM_FAZE = Folder::FONTS + "StormFaze.otf";
	}

	namespace Utility
	{
		const inline char* Empty = "";

		const inline char* GameTitle = "MY GAME";
		
		const inline char* WindowHeight = "WINDOW HEIGHT: ";
		const inline char* WindowWidth = "WINDOW WIDTH: ";
	}
}
