#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

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

int main()
{
    // Get input data
    std::vector<std::string> lines = read_lines_from_file("input.txt");

    // Map strings to numbers
    std::map<std::string, int> mappings = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}};

    // Algorithm
    int sum = 0;
    for (auto line : lines)
    {
        std::vector<int> digits = {};

        for (int i = 0; i < line.length(); i++)
        {
            if (line.at(i) >= '0' && line.at(i) <= '9')
            {
                digits.push_back(line.at(i) - '0');
            }
            else
            {
                for (auto const &[key, value] : mappings)
                {
                    if (i + key.length() <= line.length())
                    {
                        if (line.substr(i, key.size()) == key)
                        {
                            digits.push_back(value);
                        }
                    }
                }
            }
        }

        // Get first last + append
        int currentNumber = digits.at(0) * 10 + digits.back();

        // Sum
        sum += currentNumber;
    }

    std::cout << "Sum: " << sum << "\n";

    return 0;
}
// 26848
