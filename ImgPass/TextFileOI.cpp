#include "TextFileOI.h"


TextFileIO::TextFileIO() {

}


bool TextFileIO::ReadFile(std::string& text, std::string location) {
	std::string line;
	text = "";
	std::ifstream file(location += ".txt");
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			text += (line + "\n");
		}
		file.close();
	}
	else return false;
	return true;
}


bool TextFileIO::WriteFile(std::string text, std::string location) {
	std::ofstream file(location += ".txt");
	if (file.is_open())
	{
		file << text;
		file.close();
	}
	else return false;
	return true;
}
