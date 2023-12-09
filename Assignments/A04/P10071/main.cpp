#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");
  if (!inputFile.is_open() || !outputFile.is_open()) {
    cerr << "Error opening file(s)" << endl;
    return 1;
  }

  int v, t;
  while (inputFile >> v >> t) {
    int displacement = 2*v*t;
    outputFile << displacement << endl;
  }

  inputFile.close();
  outputFile.close();
  return 0;
}