#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

//Find the x and y in "mul(x,y)"
vector<int> findNumbers(const string& mul) {
    vector<int> numbers;
    regex numberPattern("[0-9]+");
    smatch match;
    string::const_iterator searchStart(mul.cbegin());

    while (regex_search(searchStart, mul.cend(), match, numberPattern)) {
        numbers.push_back(stoi(match.str()));
        searchStart = match.suffix().first;
    }

    return numbers;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 0;
    }
    stringstream buffer;
    buffer << file.rdbuf();
    string fileContents = buffer.str();
    regex pattern("mul\\([0-9]+,[0-9]+\\)");  // Match mul(x,y) pattern
    smatch match;
    int result = 0;

    // Find all "mul(x,y)" patterns in the line
    while (regex_search(fileContents, match, pattern)) {
        vector<int> numbers = findNumbers(match.str());  // Extract numbers from the matched string
        
        //The vector only has 2 numbers anyway so access them directly
        result += numbers[0] * numbers[1];  

        fileContents = match.suffix().str();  // Move to the rest of the line after the current match
    }

    cout << "Result: " << result << endl;  
    return 0;
}
