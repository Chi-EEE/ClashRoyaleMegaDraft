#pragma once
#include <algorithm>	// For generating random string
#include <fstream>
class Global
{
public:
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