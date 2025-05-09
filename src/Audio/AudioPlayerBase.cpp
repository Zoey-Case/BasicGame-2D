#include "Audio/AudioPlayerBase.h"

#include "Timers/Clock.h"

namespace Audio
{
	AudioPlayerBase::AudioPlayerBase(const std::string& filePath) { this->filePath = filePath; }

	AudioPlayerBase::~AudioPlayerBase() { CloseAudioDevice(); }
	
	void AudioPlayerBase::Load() { InitAudioDevice(); }
}
