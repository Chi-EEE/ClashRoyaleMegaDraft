#include <iostream>
#include <fstream>
#include <string>

#include <sys/stat.h>
#include <string>
#include <fstream>

#include "SpellSetHandler.h"

inline bool exists_test3(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

int main(int argc, char** argv)
{
    std::string myText;
    std::ifstream MyFile("assets/spell_sets.csv");
    while (std::getline(MyFile, myText)) {
        // Output the text from the file
        std::cout << myText;
    }

    // Close the file
    MyFile.close();
    return 0;
}
