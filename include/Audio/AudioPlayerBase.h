#pragma once

#include <string>

namespace Audio
{
	class AudioPlayerBase
	{
	public:
		AudioPlayerBase(const std::string& filePath);
		virtual ~AudioPlayerBase();
		virtual void Load();
	
	protected:
		std::string filePath;
	};
}