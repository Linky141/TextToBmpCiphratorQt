#pragma once
#include <string>
#include <fstream>


class TextFileIO
{
private:
	std::string text;
public:
	TextFileIO();

	void setText(std::string val) { text = val; }
	std::string getText() { return text; }

	bool ReadFile(std::string& text, std::string location);
	bool WriteFile(std::string text, std::string location);

};