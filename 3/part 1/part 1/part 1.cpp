#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>


using namespace std;

string filterLine(const string& line) {
    regex pattern("(mul([0-9]+,[0-9]+))");
    string result = "";
  
    for(int i = 0; i < line.length(); i++){
        
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
