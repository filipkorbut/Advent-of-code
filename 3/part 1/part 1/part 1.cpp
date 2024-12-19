#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

// Find the x and y in "mul(x,y)"
vector<int> findNumbers(const string &mul)
{
    vector<int> numbers;
    regex numberPattern("[0-9]+");
    smatch match;
    string::const_iterator searchStart(mul.cbegin());

    while (regex_search(searchStart, mul.cend(), match, numberPattern))
    {
        numbers.push_back(stoi(match.str()));
        searchStart = match.suffix().first;
    }

    return numbers;
}

int main()
{
    ifstream file("input.txt");
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return 0;
    }

    stringstream buffer;
    buffer << file.rdbuf(); // Read the entire file into the stringstream
    string fileContents = buffer.str();

    regex combinedPattern("do\\(\\)|don't\\(\\)|mul\\([0-9]+,[0-9]+\\)"); // Combined pattern for do(), don't(), and mul(x,y)
    smatch match;
    int result = 0;
    bool isDo = false;

    // Process the entire file content
    while (regex_search(fileContents, match, combinedPattern))
    {
        string matchStr = match.str();
        if (matchStr == "do()")
        {
            isDo = true;
        }
        else if (matchStr == "don't()")
        {
            isDo = false;
        }
        else 
        {
            vector<int> numbers = findNumbers(matchStr); // Extract numbers from the matched string

            // The vector only has 2 numbers anyway, so access them directly
                if(isDo)
                result += numbers[0] * numbers[1];
                cout << numbers[0] << " * " << numbers[1] << " = " << result << endl;
                    cout<<isDo<<endl;

        }
        // Move to the rest of the file content after the current match
        fileContents = match.suffix().str();
    }

    // Output the result
    cout << "Result: " << result << endl;
    return 0;
}
