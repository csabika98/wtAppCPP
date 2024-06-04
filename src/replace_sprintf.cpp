#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

void replaceInFile(const fs::path& filePath) {
    std::ifstream fileIn(filePath);
    if (!fileIn.is_open()) {
        std::cerr << "Failed to open " << filePath << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << fileIn.rdbuf();
    std::string content = buffer.str();
    fileIn.close();

    size_t pos;
    bool modified = false;
    while ((pos = content.find("std::sprintf")) != std::string::npos) {
        size_t start = content.rfind("(", pos);
        size_t end = content.find(")", pos) + 1;
        std::string replacement = "std::snprintf";

        // Find the buffer and size arguments to place within snprintf
        size_t bufStart = content.find("(", pos) + 1;
        size_t bufEnd = content.find(",", bufStart);
        std::string bufferArg = content.substr(bufStart, bufEnd - bufStart);

        replacement += "(" + bufferArg + ", sizeof(" + bufferArg + "),";
        content.replace(pos, 12, replacement);
        modified = true;
    }

    if (modified) {
        std::ofstream fileOut(filePath);
        if (!fileOut.is_open()) {
            std::cerr << "Failed to open " << filePath << " for writing" << std::endl;
            return;
        }
        fileOut << content;
        fileOut.close();
        std::cout << "Updated " << filePath << std::endl;
    }
}

void processDirectory(const fs::path& directory) {
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            const auto& path = entry.path();
            if (path.extension() == ".h" || path.extension() == ".cpp") {
                replaceInFile(path);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <directory>" << std::endl;
        return 1;
    }

    fs::path directory = argv[1];
    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        std::cerr << "Invalid directory: " << directory << std::endl;
        return 1;
    }

    processDirectory(directory);
    return 0;
}
