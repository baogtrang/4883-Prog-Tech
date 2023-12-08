#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("input.txt"); 
    ofstream outputFile("output.txt"); 

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int T, n, m;
    inputFile >> T; // Read the number of test cases

    for (int i = 0; i < T; ++i) {
        inputFile >> n >> m;

        // Calculate the number of sonars needed for rows and columns, rounding up
        int sonarsForRow = (n - 2 + 2) / 3; // +2 for rounding up
        int sonarsForColumn = (m - 2 + 2) / 3; // +2 for rounding up

        // Total sonars needed
        int totalSonars = sonarsForRow * sonarsForColumn;

        outputFile << totalSonars << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
