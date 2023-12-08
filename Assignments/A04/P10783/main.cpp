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

    int T, a, b;
    inputFile >> T; // test cases

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        inputFile >> a >> b;
        int oddSum = 0;

        for (int i = a; i <= b; ++i) {
            if (i % 2 != 0) {
                oddSum += i; 
            }
        }
        outputFile << "Case " << caseNum << ": " << oddSum << endl; 
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
