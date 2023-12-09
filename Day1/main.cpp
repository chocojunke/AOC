#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> read_lines_from_file(const std::string& file_path) {
    std::ifstream file(file_path);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}


int main() {
    // Get input data
    std::vector<std::string> lines = read_lines_from_file("input.txt");

    // Algorithm
    int sum = 0;
    for (auto line: lines) {
        // Get line numbers
        std::vector<int> lineNumbers;
        for (auto character: line) {
            bool isNumber = character - '0' > 0 && character - '0' <= 10 ;
            if (isNumber) {
                lineNumbers.push_back(character - '0');
            }
        }

        // Get first last + append
        int currentNumber = lineNumbers.at(0) * 10 + lineNumbers.back();

        // Sum
        sum += currentNumber;
    }

    std::cout << "Sum: " << sum << "\n";

    return 0;
}
