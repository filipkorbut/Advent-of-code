#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string filterLine(const string& line) {
    string result = "";
    bool spaceNeeded = false;  // To track whether a space is needed

    // Filter line of any other characters than 'mul' and numbers
    for (int i = 0; i < line.length(); i++) {
        // If the character is a digit, add it to the result
        if (line[i] >= '0' && line[i] <= '9') {
            if (spaceNeeded && !result.empty()) {
                result += ' ';  // Add a space if needed before the number, but not at the beginning
                spaceNeeded = false;  // Reset the spaceNeeded flag
            }
            result += line[i];  // Add the digit to the result
        }
        // If a comma is found after a number, mark that a space is needed
        else if (line[i] == ',' && i > 0 && line[i - 1] >= '0' && line[i - 1] <= '9') {
            spaceNeeded = true;
        }
        // If we encounter a closing parenthesis, it's a valid separator between numbers
        else if (line[i] == ')') {
            spaceNeeded = true;  // Space is needed after a closing parenthesis
        }
    }

    return result;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 0;
    }

    int result = 0;
    string line;

    while (getline(file, line)) {
        line = filterLine(line);  

        vector<int> numbers;
        stringstream ss(line);
        string temp;

        while (ss >> temp) {
            numbers.push_back(stoi(temp)); // Convert the string to integer
        }

        // Multiply numbers in pairs and accumulate the result
        for (size_t j = 0; j + 1 < numbers.size(); j += 2) {
            result += numbers[j] * numbers[j + 1]; // Multiply and accumulate
        }
    }

    // Output the final result after processing all lines
    cout << "Total result: " << result << endl;
    return 0;
}
