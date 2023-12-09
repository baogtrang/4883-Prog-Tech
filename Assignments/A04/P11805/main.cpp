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

    int T, N, K, P;
    inputFile >> T; // Read the number of test cases

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        inputFile >> N >> K >> P;
        int playerWithBall = ((K - 1 + P) % N) + 1;
        outputFile << "Case " << caseNum << ": " << playerWithBall << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
