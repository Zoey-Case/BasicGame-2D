#pragma once

#include "raylib.h"
#include "Audio/AudioPlayerBase.h"

namespace Audio
{
	class MusicPlayer : public AudioPlayerBase
	{
	public:
		MusicPlayer(const std::string& filePath);
		~MusicPlayer();
		void Load() override;

		void Update(const float& deltaTime);

	private:
		Music music;
	};
}