#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

int main() {
    ifstream inputFile("input.txt"); 
    ofstream outputFile("output.txt"); 

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int T, N;
    inputFile >> T; // Read the number of test cases

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        inputFile >> N; // read the number of creatures
        int maxSpeed = 0, speed;

        for (int i = 0; i < N; ++i) {
            inputFile >> speed;
            maxSpeed = max(maxSpeed, speed); // update the maximum speed
        }

        outputFile << "Case " << caseNum << ": " << maxSpeed << endl; 
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
