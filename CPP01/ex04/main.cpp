#include <iostream>
#include <string>
#include <fstream>

static int print_error(const std::string& msg) {
    std::cerr << msg << '\n';
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 4)
        return print_error("Wrong parameters. Usage: ./replace <filename> <s1> <s2>");

    const std::string inName = argv[1];
    const std::string s1     = argv[2];
    const std::string s2     = argv[3];

    if (s1.empty())
        return print_error("Search string (s1) cannot be empty.");

    std::ifstream inFile(inName.c_str());
    if (!inFile)
        return print_error("Failed to open input file.");

    const std::string outName = inName + ".replace";
    std::ofstream outFile(outName.c_str());
    if (!outFile)
        return print_error("Failed to create output file.");

    std::string line;
    while (std::getline(inFile, line)) {
        std::string::size_type from = 0;
        std::string::size_type pos;

        while ((pos = line.find(s1, from)) != std::string::npos) {
            outFile << line.substr(from, pos - from);
            outFile << s2;
            from = pos + s1.length();
        }
        outFile << line.substr(from) << '\n';
    }
    return 0;
}
