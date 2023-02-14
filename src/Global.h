#pragma once
#include <sys/stat.h>
#include <fstream>
class Global
{
public:
	static bool fileExists(const std::string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}

	static bool endOfFile(std::ifstream& file) {
		return (file.peek() == EOF) && (file.eof());
	}
private:
	Global() {

	}
};