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
		int c = file.peek();
		if (c == EOF) {
			if (file.eof())
				return true;
			else
				return false;
		}
		else
			return false;
	}
private:
	Global() {

	}
};