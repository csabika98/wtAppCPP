#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

void replaceInFile(const fs::path& filePath) {
    std::ifstream fileIn(filePath, std::ios::in);
    if (!fileIn.is_open()) {
        std::cerr << "Failed to open " << filePath << " for reading" << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << fileIn.rdbuf();
    std::string content = buffer.str();
    fileIn.close();

    size_t pos;
    bool modified = false;

    // Correct previous incorrect replacements
    while ((pos = content.find("std::snprintf(buf, sizeof(buf), (buf,")) != std::string::npos) {
        size_t start = content.find("(", pos) + 1;
        size_t end = content.find(")", start);
        std::string args = content.substr(start, end - start);

        // Remove the duplicated buffer argument
        size_t firstComma = args.find(",");
        std::string bufferArg = args.substr(0, firstComma);
        std::string remainingArgs = args.substr(firstComma + 1);
        std::string newArgs = bufferArg + ", sizeof(" + bufferArg + "), " + remainingArgs;
        content.replace(start, end - start, newArgs);

        modified = true;
    }

    // Replace std::sprintf with std::snprintf
    while ((pos = content.find("std::sprintf")) != std::string::npos) {
        size_t start = content.find("(", pos) + 1;
        size_t end = content.find(")", start);
        std::string args = content.substr(start, end - start);

        size_t firstComma = args.find(",");
        std::string bufferArg = args.substr(0, firstComma);

        std::string replacement = "std::snprintf(" + bufferArg + ", sizeof(" + bufferArg + "),";
        content.replace(pos, 12, replacement);

        modified = true;
    }

    if (modified) {
        std::ofstream fileOut(filePath, std::ios::out | std::ios::trunc);
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


