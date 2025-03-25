#include "Debug.h"
#include <iostream>

void Debug::Log(const std::string& text)
{
	std::string newText = "LOG:\n    ";

	for (int index = 0; index < static_cast<int>(text.length()); index++)
	{
		newText += text[index];
		if (text[index] == '\n') { newText += "    "; }
	}

	newText += "\n\n";
	std::cout << newText;
}

void Debug::Warning(const std::string& text)
{
	std::string newText = "WARNING:\n    ";

	for (int index = 0; index < static_cast<int>(text.length()); index++)
	{
		if (text[index] == '\n')
		{
			newText += "!\n    ";
			continue;
		}

		newText += toupper(text[index]);
	}

	newText += "\n\n";
	std::cout << newText;
}

void Debug::Error(const std::string& text)
{
	std::string newText = "**ERROR**:\n    ";

	for (int index = 0; index < static_cast<int>(text.length()); index++)
	{
		if (text[index] == '\n')
		{
			newText += "!!!!!\n    ";
			continue;
		}

		newText += toupper(text[index]);
	}

	newText += "\n\n";
	std::cout << newText;
}