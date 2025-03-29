#include "Audio/MusicPlayer.h"
#include "Strings/StringLibrary.h"

namespace Audio
{
	MusicPlayer::MusicPlayer(const std::string& filePath) : AudioPlayerBase(Strings::Audio::music) {}

	MusicPlayer::~MusicPlayer()
	{
		UnloadMusicStream(music);

		AudioPlayerBase::~AudioPlayerBase();
	}

	void MusicPlayer::Load()
	{
		AudioPlayerBase::Load();

		music = LoadMusicStream(filePath.c_str());
		PlayMusicStream(music);
	}

	void MusicPlayer::Update(const float& deltaTime)
	{
		UpdateMusicStream(music);
	}
}