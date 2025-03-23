#pragma once
#include "Strings/StringLibrary.h"


namespace Debugging
{
	class Debug
	{
	public:
		// Debug Class Constructor
		Debug();

		// Low-Severity Console Log
		static void Log(const std::string&);
	
		// Mid-Severity Console Log
		static void Warning(const std::string&);
	
		// High-Severity Console Log
		static void Error(const std::string&);
	};
}