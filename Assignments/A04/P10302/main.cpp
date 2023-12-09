#include <iostream>
#include <fstream>
using namespace std;

long long sumOfCubes(int n) {
  long long sum = (static_cast<long long>(n) * (n+1)/2);
  return sum*sum;
}

int main(){
  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");
  if (!inputFile.is_open() ||!outputFile.is_open()){
    cerr << "Error opening files!" << endl;
    return 1;
  }

  int n;
  while (inputFile >>n) {
    long long result = sumOfCubes(n);
    outputFile << result << endl;
  }

  inputFile.close();
  outputFile.close();
}