#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> read_lines_from_file(const std::string &file_path)
{
    std::ifstream file(file_path);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

std::vector<std::string> splitString(const std::string &str, char delimiter)
{
    std::vector<std::string> result;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}

int main()
{
    // Get input data
    std::vector<std::string> lines = read_lines_from_file("input.txt");

    // Algorithm
    int sum = 0;
    int minRed = 0;
    int minGreen = 0;
    int minBlue = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        // Current line
        std::string line = lines[i];

        // Get line words
        std::vector<std::string> gameValues = splitString(line, ':');
        std::vector<std::string> tries = splitString(gameValues[1], ';');

        minRed = 0;
        minGreen = 0;
        minBlue = 0;

        for (auto tryElement : tries)
        {
            std::vector<std::string> cubes = splitString(tryElement, ' ');
            for (int i = 0; i < cubes.size(); i++)
            {
                if (cubes[i] == "red" || cubes[i] == "red," || cubes[i] == "red;")
                {
                    minRed = std::stoi(cubes[i - 1]) > minRed ? std::stoi(cubes[i - 1]) : minRed;
                }
                if (cubes[i] == "green" || cubes[i] == "green," || cubes[i] == "green;")
                {
                    minGreen = std::stoi(cubes[i - 1]) > minGreen ? std::stoi(cubes[i - 1]) : minGreen;
                }
                if (cubes[i] == "blue" || cubes[i] == "blue," || cubes[i] == "blue;")
                {
                    minBlue = std::stoi(cubes[i - 1]) > minBlue ? std::stoi(cubes[i - 1]) : minBlue;
                }
            }
        }

        // Sum
        sum += minRed * minGreen * minBlue;
    }

    std::cout << "Sum: " << sum << "\n";

    return 0;
}
// 26848
