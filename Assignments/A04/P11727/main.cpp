#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream inputFile("input.txt"); 
  ofstream outputFile(
      "output.txt"); 
  if (!inputFile.is_open() || !outputFile.is_open()) {
    cerr << "Error opening files!" << endl;
    return 1;
  }

  int T, salaries[3];
  inputFile >> T;

  for (int i = 1; i <= T; ++i) {
    inputFile >> salaries[0] >> salaries[1] >> salaries[2];

    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2 - j; ++k) {
        if (salaries[k] > salaries[k + 1]) {
          swap(salaries[k], salaries[k + 1]);
        }
      }
    }
    outputFile << "Case " << i << ": " << salaries[1] << endl;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}
