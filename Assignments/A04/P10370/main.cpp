#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // For std::setprecision
using namespace std;

int main() {
    ifstream inputFile("input.txt"); 
    ofstream outputFile("output.txt"); 
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int C, N;
    inputFile >> C; // Read the number of test cases

    for (int i = 0; i < C; ++i) {
        inputFile >> N; // Read the number of students
        vector<int> scores(N);
        int sum = 0;

        for (int j = 0; j < N; ++j) {
            inputFile >> scores[j];
            sum += scores[j];
        }

        double average = static_cast<double>(sum) / N;
        int countAboveAverage = 0;

        for (int score : scores) {
            if (score > average) {
                countAboveAverage++;
            }
        }

        double percentageAboveAverage = static_cast<double>(countAboveAverage) / N * 100;
        outputFile << fixed << setprecision(3) << percentageAboveAverage << "%" << endl; 
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
